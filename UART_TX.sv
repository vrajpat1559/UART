// =============================================================================
// uart_tx.sv  —  UART Transmitter (8N1)
//
// The module's job: take a byte, and shift it out one bit at a time on the `tx`
// wire in proper UART frame order (start bit, 8 data bits LSB-first, stop bit),
// holding each bit on the wire for exactly one "bit period."
// =============================================================================

module uart_tx #(
    // --- Parameters: compile-time constants that configure the module ---
    // Making these parameters (instead of hardcoding) lets you reuse this module
    // at different clock speeds / baud rates without editing the logic. On real
    // hardware you'd instantiate with your board's true 50 MHz and 115200 baud.
    parameter int CLK_FREQ_HZ = 50_000_000,  // frequency of the clk input, in Hz
    parameter int BAUD_RATE   = 115_200      // desired serial speed, in bits/sec
) (
    // --- Ports: the module's connections to the outside world ---
    input  logic       clk,       // system clock — everything advances on its rising edge
    input  logic       rst_n,     // active-LOW reset: when 0, force module to known state
    input  logic       tx_start,  // pulse HIGH 1 cycle to request "send this byte now"
    input  logic [7:0] tx_data,   // the byte to send; you latch it when tx_start fires
    output logic       tx,        // THE serial output wire. Idles high, carries the frame.
    output logic       tx_busy,   // HIGH while a frame is in progress (so caller waits)
    output logic       tx_done    // 1-cycle pulse when a frame finishes (handshake signal)
);

    // -------------------------------------------------------------------------
    // Derived constant: how many clock cycles equal one UART bit.
    // This is the heart of the timing. At 50MHz / 115200 baud, this is ~434.
    // You'll count clk cycles up to this number to "hold" each bit on the wire.
    // -------------------------------------------------------------------------
    localparam int CYCLES_PER_BIT = CLK_FREQ_HZ / BAUD_RATE;

    // -------------------------------------------------------------------------
    // State enum: the four phases of transmitting one byte.
    // An FSM (finite state machine) means "the module is always in exactly one
    // of these named states, and moves between them on defined conditions."
    // TODO: declare an enum with IDLE, START_BIT, DATA_BITS, STOP_BIT
    //   - IDLE      : doing nothing, tx wire held high, waiting for tx_start
    //   - START_BIT : driving the wire low for one bit period (the "0" start)
    //   - DATA_BITS : shifting out the 8 data bits, one per bit period
    //   - STOP_BIT  : driving the wire high for one bit period (the "1" stop)
    // -------------------------------------------------------------------------
	 
	 typedef enum logic [1:0] {
		IDLE,
		START_BIT,
		DATA_BITS,
		STOP_BIT
		} state_t;
		
		
	// TODO: typedef enum ... state_t;
   // TODO: declare two signals of that type: `state` (current) and `state_next`

		state_t state, state_next;
	 
    
    // -------------------------------------------------------------------------
    // Internal registers you'll need:
    // TODO: cycle_cnt  — counts clk cycles within the current bit (0 .. CYCLES_PER_BIT-1)
    //                    Tells you when one bit period has elapsed.
    // TODO: bit_idx    — which of the 8 data bits you're currently sending (0 .. 7)
    // TODO: data_shift — a latched copy of tx_data, so the caller can change tx_data
    //                    after starting without corrupting the in-flight byte.
    // -------------------------------------------------------------------------
	logic [8:0] cycle_cnt;
	logic [2:0] bit_idx;
	logic [7:0' data_shif;
	 
    // =========================================================================
    // BLOCK 1: State register (sequential — always_ff, triggered by clock edge)
    //
    // Job: on every rising clock edge, update `state` to `state_next`.
    // On reset (rst_n == 0), force state back to IDLE.
    // This is the ONLY place `state` gets assigned. "always_ff" = this becomes
    // real flip-flops in hardware.
    // =========================================================================
    always_ff @(posedge clk) begin
        if (!rst_n)  state <= IDLE;        // reset to known state
        else         state <= state_next;  // otherwise advance
    end

    // =========================================================================
    // BLOCK 2: Cycle counter (sequential — always_ff)
    //
    // Job: count clock cycles so you know when one bit period (CYCLES_PER_BIT)
    // has passed. Reset it to 0 when you change states (fresh count for each
    // new bit) and when it reaches its max. This is your "bit-period timer."
    // =========================================================================
    // TODO: on each clk edge:
    //   - if reset: cycle_cnt <= 0
    //   - if about to change state: cycle_cnt <= 0  (start the next bit fresh)
    //   - else if counting: increment, wrapping back to 0 at CYCLES_PER_BIT-1

    // =========================================================================
    // BLOCK 3: Bit index counter (sequential — always_ff)
    //
    // Job: track which of the 8 data bits you're on. Only advances while in
    // DATA_BITS, and only once per completed bit period (when cycle_cnt hits
    // its max). Reset to 0 whenever you're not in DATA_BITS so the next byte
    // starts from bit 0.
    // =========================================================================
    // TODO: on each clk edge:
    //   - reset -> bit_idx <= 0
    //   - in DATA_BITS and bit period just completed -> bit_idx <= bit_idx + 1
    //   - not in DATA_BITS -> bit_idx <= 0

    // =========================================================================
    // BLOCK 4: Latch the input byte (sequential — always_ff)
    //
    // Job: when a transmission starts (IDLE and tx_start), copy tx_data into
    // data_shift. Why: the caller might change tx_data on their next byte while
    // you're still sending this one — latching protects the in-flight data.
    // =========================================================================
    // TODO: on each clk edge:
    //   - if (state == IDLE && tx_start) data_shift <= tx_data;

    // =========================================================================
    // BLOCK 5: Next-state logic (combinational — always_comb)
    //
    // Job: decide what the NEXT state should be, based on current state + inputs.
    // This is pure combinational logic (no clock) — it just computes state_next.
    // Default state_next = state (stay put) unless a condition says otherwise:
    //   - IDLE:      if tx_start -> START_BIT
    //   - START_BIT: if bit period done -> DATA_BITS
    //   - DATA_BITS: if bit period done AND bit_idx == 7 -> STOP_BIT
    //   - STOP_BIT:  if bit period done -> IDLE
    // =========================================================================
    // TODO:
    //   always_comb begin
    //       state_next = state;   // default: hold
    //       case (state) ... endcase
    //   end

    // =========================================================================
    // BLOCK 6: Output logic — drive the tx wire (combinational — always_comb)
    //
    // Job: set what value the `tx` wire carries, based purely on current state:
    //   - IDLE      -> 1 (idle high)
    //   - START_BIT -> 0 (start bit is always 0)
    //   - DATA_BITS -> the current data bit: data_shift[bit_idx]  (LSB first!)
    //   - STOP_BIT  -> 1 (stop bit is always 1)
    // =========================================================================
    // TODO:
    //   always_comb begin
    //       case (state) ... endcase
    //   end

    // =========================================================================
    // BLOCK 7: Status outputs
    //
    // tx_busy: simply HIGH whenever you're not in IDLE (a frame is in flight).
    //          This is combinational — one assign line.
    // tx_done: a 1-cycle pulse right as the frame finishes (STOP_BIT -> IDLE).
    //          Useful as a handshake so external logic knows "byte sent."
    //          This one is registered (a flop) so it's a clean single pulse.
    // =========================================================================
    // TODO: assign tx_busy = (state != IDLE);
    // TODO: register tx_done to pulse when leaving STOP_BIT for IDLE

endmodule