// =============================================================================
// tb_uart_tx.sv  —  Testbench for the UART transmitter
// =============================================================================

`timescale 1ns/1ps

module tb_uart_tx;

    // ---- JOB 1: Simulation parameters ----
    localparam int CLK_FREQ_HZ    = 1_000_000;   // 1 MHz sim clock
    localparam int BAUD_RATE      = 10_000;      // -> 100 cycles per bit
    localparam int CYCLES_PER_BIT = CLK_FREQ_HZ / BAUD_RATE;
    localparam int CLK_PERIOD_NS  = 1000;        // 1 MHz -> 1000 ns period

    // ---- JOB 2a: One signal per DUT port ----
    logic       clk;
    logic       rst_n;
    logic       tx_start;
    logic [7:0] tx_data;
    logic       tx;
    logic       tx_busy;
    logic       tx_done;

    // Bookkeeping counters (testbench-only)
    int errors    = 0;
    int tests_run = 0;

    // ---- JOB 2b: Instantiate the DUT ----
    uart_tx #(
        .CLK_FREQ_HZ(CLK_FREQ_HZ),
        .BAUD_RATE(BAUD_RATE)
    ) dut (
        .clk(clk),
        .rst_n(rst_n),
        .tx_start(tx_start),
        .tx_data(tx_data),
        .tx(tx),
        .tx_busy(tx_busy),
        .tx_done(tx_done)
    );

    // ---- JOB 3: Clock generator ----
    always #(CLK_PERIOD_NS/2) clk = ~clk;

    // ---- JOB 4a: Send one byte and check the serial output ----
    task automatic send_and_check(input logic [7:0] data);
        logic [7:0] captured;
        tests_run++;

        // wait for idle, then issue the start pulse
        @(posedge clk);
        while (tx_busy) @(posedge clk);

        tx_data  = data;
        tx_start = 1'b1;
        @(posedge clk);
        tx_start = 1'b0;

        // check START bit (should be 0), sampled at its center
        repeat (CYCLES_PER_BIT/2) @(posedge clk);
        if (tx !== 1'b0) begin
            $display("ERROR: start bit expected to be 0, got %b", tx);
            errors++;
        end
        repeat (CYCLES_PER_BIT/2) @(posedge clk);

        // capture 8 DATA bits, LSB first, each sampled at center
        for (int i = 0; i < 8; i++) begin
            repeat (CYCLES_PER_BIT/2) @(posedge clk);
            captured[i] = tx;
            repeat (CYCLES_PER_BIT/2) @(posedge clk);
        end

        // check STOP bit (should be 1)
        repeat (CYCLES_PER_BIT/2) @(posedge clk);
        if (tx !== 1'b1) begin
            $display("ERROR: stop bit expected to be 1, got %b", tx);
            errors++;
        end
        repeat (CYCLES_PER_BIT/2) @(posedge clk);

        // compare
        if (captured !== data) begin
            $display("ERROR: data mismatch, sent 0x%02h, got 0x%02h", data, captured);
            errors++;
        end else begin
            $display("PASS: sent 0x%02h, got 0x%02h", data, captured);
        end
    endtask

    // ---- JOB 4b: Main test sequence ----
    initial begin
        $dumpfile("uart_tx.vcd");
        $dumpvars(0, tb_uart_tx);

        // init all inputs to known values
        clk      = 0;
        rst_n    = 0;
        tx_start = 0;
        tx_data  = 0;

        // apply reset, then release
        rst_n = 1'b0;
        repeat (2) @(posedge clk);
        rst_n = 1'b1;
        repeat (2) @(posedge clk);

        // sanity: line should idle high after reset
        if (tx !== 1'b1) begin
            $display("ERROR: tx does not idle high after reset");
            errors++;
        end

        // directed tests (deliberate edge cases)
        send_and_check(8'h00);
        send_and_check(8'hFF);
        send_and_check(8'hAA);
        send_and_check(8'h55);
        send_and_check(8'h41);

        // randomized tests
        for (int i = 0; i < 20; i++) begin
            send_and_check($urandom_range(0, 255));
        end

        // final report
        $display("=== Testbench complete: %0d tests run, %0d errors ===", tests_run, errors);
        if (errors == 0)
            $display("*** ALL TESTS PASSED ***");
        else
            $display("*** %0d TEST(S) FAILED ***", errors);

        $finish;
    end

    // ---- JOB 5: Safety timeout ----
    initial begin
        #50_000_000;
        $display("ERROR: TIMEOUT - DUT likely hung");
        $finish;
    end

endmodule