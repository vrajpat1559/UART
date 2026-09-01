`timescale 1ns/1ps

module tb_uart_rx;

	//SIMULATION PARAMETERS
	localparam int CLK_FREQ_HZ = 1_000_000;
	localparam int BAUD_RATE = 10_000;
	localparam int CYCLES_PER_BIT = CLK_FREQ_HZ/ BAUD_RATE;
	localparam int CLK_PERIOD_NS = 1000;
	
	//ONE SIG PER DUT PORT
	logic clk;
	logic rst_n;
	logic rx;
	logic [7:0] rx_data;
	logic rx_valid;
	logic rx_busy;
	
	//BOOKKEEPING COUNTERS
	int errors = 0;
	int tests_run = 0;
	
	
	//INSTANTIATE THE DUT
	uart_rx #(.CLK_FREQ_HZ(CLK_FREQ_HZ), .BAUD_RATE(BAUD_RATE) 
	) dut (.clk(clk), .rst_n(rst_n), .rx(rx), .rx_data(rx_data), .rx(rx), .rx_valid(rx_valid), .rx_busy(rx_busy));
	
	//CLOCK GENERATOR
	always #(CLK_PERIOD_NS/2) clk = ~clk;
	
	//This section checks for each bit and verifies it basicallty just checking each bit and seeing if it checks out
	//drives the 8 data bits
	task automatic send_frame(input logic [7:0] data);
	//starts the cycle read
	//drives the start bit
	rx = 0;
	repeat (CYCLES_PER_BIT) @(posedge clk);
	for(int i =0; i < 8; i++) begin
		rx = data[i];
		repeat (CYCLES_PER_BIT) @(posedge clk);
	end
	rx = 1;
	repeat (CYCLES_PER_BIT) @(posedge clk);
	
	//redo this comment later this part is the checking half after the frame is all driven
	while(!rx_valid) @(posedge clk);
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
	$dumpfile("uar
	