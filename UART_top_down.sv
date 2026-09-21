module uart_top_down #(

parameter int CLK_FREQ_HZ = 50_000_000,
parameter int BAUD_RATE = 115_200
) (
	input logic clk;
	input logic btn_rst_n;
	input logic btn_send_n;
	input logic [7:0] led;
	output logic uart_tx_pin;
	input logic uart_rx_pin;
);
	//RX
	uart_rx #(.CLK_FREQ_HZ(CLK_FREQ_HZ), .BAUD_RATE(BAUD_RATE) 
	) dut (.clk(clk), .rst_n(rst_n), .rx_data(rx_data), .rx_valid(rx_valid), .rx_busy(rx_busy), .rx(uart_rx_pin));
	
	//TX
	uart_tx #(.CLK_FREQ_HZ(CLK_FREQ_HZ), .BAUD_RATE(BAUD_RATE) 
	) dut_two (.clk(clk), .rst_n(rst_n), .tx_data(tx_data), .tx_busy(tx_busy), .tx_done(tx_done), .tx_start(tx_start), .tx(uart_tx_pin));
	
	