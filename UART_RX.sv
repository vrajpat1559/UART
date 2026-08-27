module uart_rx #(parameter int CLK_FREQ_HZ = 50_000_000, parameter int BAUD_RATE = 115_200)

(
	input logic clk,
	input logic rst_n,
	input logic rx,
	output logic rx_busy,
	output logic rx_valid,
	output logic [7:0] rx_data
);

	localparam int CYCLES_PER_BIT = CLK_FREQ_HZ / BAUD_RATE;

	typedef enum logic [1:0] {IDLE, START_BIT, DATA_BITS, STOP_BIT} state_t;
	
	state_t state, state_next;
