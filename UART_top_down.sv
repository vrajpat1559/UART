module uart_top_down #(

parameter int CLK_FREQ_HZ = 50_000_000,
parameter int BAUD_RATE = 115_200
) (
	input logic clk;
	input logic btn_rst_n;
	input logic btn_send_n;
	input logic uart_rx_pin;
	output logic [7:0] led;
	output logic uart_tx_pin;
	
	//signals
	logic tx_start;
	logic tx_data;
	logic rx_data;
	logic rx_valid;
	logic rx_busy;
	logic tx_busy;
	logic tx_done;
	logic btn_sync_1;
	logic btn_s
	
);
	//RX
	uart_rx #(.CLK_FREQ_HZ(CLK_FREQ_HZ), .BAUD_RATE(BAUD_RATE) 
	) u_tx (.clk(clk), .rst_n(btn_rst_n), .rx_data(rx_data), .rx_valid(rx_valid), .rx_busy(rx_busy), .rx(uart_rx_pin));
	
	//TX
	uart_tx #(.CLK_FREQ_HZ(CLK_FREQ_HZ), .BAUD_RATE(BAUD_RATE) 
	) u_rx (.clk(clk), .rst_n(btn_rst_n), .tx_data(tx_data), .tx_busy(tx_busy), .tx_done(tx_done), .tx_start(tx_start), .tx(uart_tx_pin));
	
	//button syncrhonizer
	always_ff @(posedge clk) begin
    if (!btn_rst_n) begin
        btn_sync_1 <= 1'b1;
        btn_sync_2 <= 1'b1;
    end else begin
        btn_sync_1 <= btn_send_n;
        btn_sync_2 <= btn_sync_1;
    end
end

assign tx_start = (btn_sync_2 == 1'b1 && btn_sync_1 == 1'b0);
	
	
endmodule