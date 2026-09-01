`timescale 1ns/1ps

module tb_uart_rx;

	//SIMULATION PARAMETERS
	localparam int CLK_FREQ_HZ = 1_000_000;
	localparam int BAUD_RATE = 6250;
	localparam int CYCLES_PER_BIT = CLK_FREQ_HZ/ BAUD_RATE;
	localparam int CLK_PERIOD_NS = 1000;
	
	//ONE SIG PER DUT PORT
	logic clk;
	logic rst_n;
	logic rx;
	logic [7:0] rx_data;
	logic rx_valid;
	logic rx_busy;
	logic saw_valid;
	
	//BOOKKEEPING COUNTERS
	int errors = 0;
	int tests_run = 0;
	
	//WATCHER FUNCTION
	always @(posedge clk) begin
	if(rx_valid == 1)
		saw_valid = 1;
	end
	
	
	
	//INSTANTIATE THE DUT
	uart_rx #(.CLK_FREQ_HZ(CLK_FREQ_HZ), .BAUD_RATE(BAUD_RATE) 
	) dut (.clk(clk), .rst_n(rst_n), .rx(rx), .rx_data(rx_data), .rx_valid(rx_valid), .rx_busy(rx_busy));
	
	//CLOCK GENERATOR
	always #(CLK_PERIOD_NS/2) clk = ~clk;
	
	//This section checks for each bit and verifies it basicallty just checking each bit and seeing if it checks out
	//drives the 8 data bits
	task automatic send_frame(input logic [7:0] data);
	//starts the cycle read
	//drives the start bit
	saw_valid = 0;
	rx = 0;
	repeat (CYCLES_PER_BIT) @(posedge clk);
	for(int i =0; i < 8; i++) begin
		rx = data[i];
		repeat (CYCLES_PER_BIT) @(posedge clk);
	end
	rx = 1;
	repeat (CYCLES_PER_BIT) @(posedge clk);
	
	//redo this comment later this part is the checking half after the frame is all driven
	while(!saw_valid) @(posedge clk);
	tests_run++;
	if(rx_data !== data) begin
		$display("ERROR: Mismatch sent %02h, got %02h", data, rx_data);
		errors++;
	end else begin
		$display("PASS: sent %02h, got %02h", data, rx_data);
	end
		
endtask
	//MAIN TEST SEQUENCE
	initial begin
		$dumpfile("uart.rx.vcd");
		$dumpvars(0, tb_uart_rx);
		
		//INITIALIZE ALL INPUTS
		clk = 0;
		rst_n =0;
		rx = 1;
		
		//APPLY RESET, THEN RELEASE
		rst_n = 1'b0;
		repeat (2) @(posedge clk);
		rst_n = 1'b1;
		repeat (2) @(posedge clk);
		
		//TEST CASES
		send_frame(8'h00);
		send_frame(8'h11);
		send_frame(8'hFF);
		send_frame(8'h32);
		send_frame(8'h41);
		
		//RANDOMIZED TESTING
		for(int i = 0; i < 20; i++) begin
			send_frame($urandom_range(0,255));
		end
		
		//FINAL REPORT	
		$display("Testbench complete, %0d tests, run. %0d errors", tests_run, errors);
		if (errors == 0)
			$display("**** ALL TESTS PASSED ****");
		else
			$display("**** %0d TESTS(S) FAILED ****", errors);
		
		$finish;
	end
	
	//TIMEOUT
	initial begin
		#50_000_000;
		$display("ERROR: TIMEOUT - DUT most likely hung");
		$finish;
	end

endmodule
		
		
		
	