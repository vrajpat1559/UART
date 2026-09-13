`timescale 1ns/1ps

module tb_loopback

	//SIMULATION PARAMETERS
	localparam int CLK_FREQ_HZ = 1_000_000;
	localparam int BAUD_RATE = 6250;
	localparam int CYCLES_PER_BIT = CLK_FREQ_HZ/BAUD_RATE;
	localparam int CLK_PERIOD_NS = 1000;
	
	
	//INSTANTIATE ALL PARAMETERS (also link tx and rx together)
	logic clk;
	logic rst_n;
	logic tx = rx
	logic [7:0] rx_data;
	logic rx_valid;
	logic rx_busy;
	logic saw_valid;
	logic tx_busy;
	logic tx_done;
	logic tx_start;
	
	//BOOKKEEPING COUNTERS
	int errors = 0;
	int tests_run = 0;
	
	//INSTANTIATE BOTH MODULES WITH PARAMETERS PASSED IN
	//RX
	uart_rx #(.CLK_FREQ_HZ(CLK_FREQ_HZ), .BAUD_RATE(BAUD_RATE) 
	) dut (.clk(clk), .rst_n(rst_n), .rx(rx), .rx_data(rx_data), .rx_valid(rx_valid), .rx_busy(rx_busy));
	
	//TX
	uart_tx #(.CLK_FREQ_HZ(CLK_FREQ_HZ), .BAUD_RATE(BAUD_RATE) 
	) dut (.clk(clk), .rst_n(rst_n), .tx(tx), .tx_data(tx_data), .tx_busy(tx_busy), .tx_done(tx_done), .tx_start(tx_start));
	
	//CLOCK GENERATOR
	always #(CLK_PERIOD_NS/2) clk = ~clk;
	
	//TASK 1
	task automatic tx_frame(input logic [7:0] data);
		tests_run++;

		@(posedge clk);
		while (tx_busy) @(posedge clk);
		tx_data = data;
		tx_start = 1'b1;
		@(posedge clk)
		tx_start = 1'b0;
		
		while(!rx_valid) @(posedge clk);
			if(rx_data !== tx_data)
			errors++;
			
		