`timescale 1ns/1ps

module tb_loopback;

	//SIMULATION PARAMETERS
	localparam int CLK_FREQ_HZ = 1_000_000;
	localparam int BAUD_RATE = 6250;
	localparam int CYCLES_PER_BIT = CLK_FREQ_HZ/BAUD_RATE;
	localparam int CLK_PERIOD_NS = 1000;
	
	
	//INSTANTIATE ALL PARAMETERS (also link tx and rx together)
	logic clk;
	logic rst_n;
	logic [7:0] rx_data;
	logic [7:0] tx_data;
	logic rx_valid;
	logic rx_busy;
	logic tx_busy;
	logic tx_done;
	logic tx_start;
	logic serial_line;
	
	//BOOKKEEPING COUNTERS
	int errors = 0;
	int tests_run = 0;
	
	//INSTANTIATE BOTH MODULES WITH PARAMETERS PASSED IN
	//RX
	uart_rx #(.CLK_FREQ_HZ(CLK_FREQ_HZ), .BAUD_RATE(BAUD_RATE) 
	) dut (.clk(clk), .rst_n(rst_n), .rx_data(rx_data), .rx_valid(rx_valid), .rx_busy(rx_busy), .rx(serial_line));
	
	//TX
	uart_tx #(.CLK_FREQ_HZ(CLK_FREQ_HZ), .BAUD_RATE(BAUD_RATE) 
	) dut_two (.clk(clk), .rst_n(rst_n), .tx_data(tx_data), .tx_busy(tx_busy), .tx_done(tx_done), .tx_start(tx_start), .tx(serial_line));
	
	//CLOCK GENERATOR
	always #(CLK_PERIOD_NS/2) clk = ~clk;
	
	//TASK 1
	task automatic tx_frame(input logic [7:0] data);
		tests_run++;

		@(posedge clk);
		while (tx_busy) @(posedge clk);
		tx_data <= data;
		tx_start <= 1'b1;
		@(posedge clk);
		tx_start <= 1'b0;
		
		while(!rx_valid) @(posedge clk);
			if(rx_data !== tx_data) begin
				errors++;
				$display("ERROR: data mismatch, needed 0x%02h, got 0x%02h", tx_data, rx_data);
			end else begin
				$display("PASS: sent 0x%02h, got 0x%02h", tx_data, rx_data);
			end
	endtask
	
	//TEST SEUQEUNCE
	initial begin
	$dumpfile("tb_loopback.vcd");
	$dumpvars(0, tb_loopback);
	
	clk = 0;
	rst_n = 0;
	tx_start = 0;
	tx_data = 0;
	
	//reset
	rst_n = 1'b0;
	repeat (2) @(posedge clk);
	rst_n = 1'b1;
	repeat (2) @(posedge clk);
	
	//edge case detection
	tx_frame(8'h00);
	tx_frame(8'hFF);
	tx_frame(8'hAA);
	tx_frame(8'h55);
	tx_frame(8'h41);
	
	//randomized testing
	for(int i =0; i < 20; i++) begin
		tx_frame($urandom_range(0,255));
	end
	
	//report line
	$display("=== Testbench complete: %0d tests run, %0d errors ===", tests_run, errors);
        if (errors == 0)
            $display("*** ALL TESTS PASSED ***");
        else
            $display("*** %0d TEST(S) FAILED ***", errors);

        $finish;
    end
	 
	//timeout
	initial begin
		#50_000_000;
		$display("ERROR: TIMEOUT - DUT hung");
		$finish;
	end
endmodule