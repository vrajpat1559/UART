module uart_rx #(parameter int CLK_FREQ_HZ = 50_000_000, parameter int BAUD_RATE = 115_200)

(
	input logic clk,
	input logic rst_n,
	input logic rx,
	output logic rx_busy,
	output logic rx_valid,
	output logic [7:0] rx_data
);
	//derived constants;
	localparam int CYCLES_PER_BIT = CLK_FREQ_HZ / BAUD_RATE;
	localparam int OVERSAMPLE = 16;
	localparam int OS_DIVISOR = CYCLES_PER_BIT/OVERSAMPLE;
	//state enum
	typedef enum logic [1:0] {IDLE, START_BIT, DATA_BITS, STOP_BIT} state_t;
	
	state_t state, state_next;

	logic rx_FF_1;
	logic rx_FF_2;
	logic [OS_DIVISOR -1:0] tick_counter;
	logic [3:0] os_count; 
	logic [2:0] bit_idx;
	logic [7:0] data_register;
	logic os_tick;
	logic rx_falling_edge;
	
	//synchronizer
	always_ff @(posedge clk) begin
	if(!rst_n) begin
		rx_FF_1 <= 1'b1;
		rx_FF_2 <= 1'b1;
	end 
	else begin
		rx_FF_1	<= rx;
		rx_FF_2  <= rx_FF_1;
	end	
end
	//oversampler
	always_ff @(posedge clk) begin
	if(!rst_n)
		tick_counter <= 0;
	else if(tick_counter == OS_DIVISOR -1)
		tick_counter <= 0;
	else
		tick_counter <= tick_counter +1;
	end
	assign os_tick = (tick_counter == OS_DIVISOR -1);

	always_ff @(posedge clk) begin
	if(!rst_n) 
		os_count <= 0;
	else if(state == IDLE)
		os_count <= 0;
	else if (state != state_next)
		os_count <=0;
	else if(os_tick)
		os_count <= os_count + 1;
	end
	//
	
	//edge detection
	assign rx_falling_edge = (rx_FF_2 == 1'b1 && rx_FF_1 == 1'b0);
	//
	
	//FSM 
	always_comb begin
	state_next = state;
	case(state)
		IDLE: if (rx_falling_edge) state_next = START_BIT;
		START_BIT: if (os_count == OVERSAMPLE/2 && os_tick) state_next = DATA_BITS;
		DATA_BITS: if(bit_idx == 7 && os_count == 15 && os_tick) state_next = STOP_BIT;
		STOP_BIT: if (os_count == OVERSAMPLE -1 && os_tick) state_next = IDLE;
	endcase
end

	//state register
	always_ff @(posedge clk) begin
		if(!rst_n) 
			state <= IDLE;
		else
			state <= state_next;
		end
		
		
	//bit index counter
	always_ff @(posedge clk) begin
	if(!rst_n)
		bit_idx <= 0;
	else if (state != DATA_BITS)
		bit_idx <= 0;
	else if (os_tick && os_count == 15)
		bit_idx <= bit_idx + 1;
	end
	
	//data capture
	always_ff @(posedge clk) begin
	if(!rst_n)
		data_register <= 8'b0;
	else if (os_count == 15 && os_tick && state == DATA_BITS)
		data_register[bit_idx] <= rx_FF_2;
	end
	
	//rx_busy
	assign rx_busy = (state != IDLE);
	
	//rx_valid
	always_ff @(posedge clk) begin
	if (!rst_n)
		rx_valid <= 1'b0;
	else
		rx_valid <= (state == STOP_BIT && state_next == IDLE);
	end
	
	//rx_data decides to use seuqential logic instead of combinational because it allows
	// clean read instead of reading garbage midway through
	always_ff @(posedge clk) begin
	if(!rst_n)
		rx_data <= 0;
	else if (state == STOP_BIT && state_next == IDLE)
		rx_data <= data_register;
	end
endmodule
	