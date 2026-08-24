// =============================================================================
// uart_tx.sv  —  UART Transmitter (8N1)
//
// The module's job: take a byte, and shift it out one bit at a time on the `tx`
// wire in proper UART frame order (start bit, 8 data bits LSB-first, stop bit),
// holding each bit on the wire for exactly one "bit period."
// =============================================================================

module uart_tx #(
    // Parameters let you reuse this module at different clock speeds / baud rates
    // without editing the logic. Instantiate with your board's real clock/baud.
    parameter int CLK_FREQ_HZ = 50_000_000,  // frequency of the clk input, in Hz
    parameter int BAUD_RATE   = 115_200      // desired serial speed, in bits/sec
) (
    input  logic       clk,       // system clock — everything advances on its rising edge
    input  logic       rst_n,     // active-LOW reset: when 0, force module to known state
    input  logic       tx_start,  // pulse HIGH 1 cycle to request "send this byte now"
    input  logic [7:0] tx_data,   // the byte to send; latched when tx_start fires
    output logic       tx,        // serial output wire. Idles high, carries the frame.
    output logic       tx_busy,   // HIGH while a frame is in progress (so caller waits)
    output logic       tx_done    // 1-cycle pulse when a frame finishes (handshake signal)
);

    // Derived constant: how many clock cycles equal one UART bit. This is the heart
    // of the timing — at 50 MHz / 115200 baud it is ~434. Each bit is held on the
    // wire for this many clk cycles.
    localparam int CYCLES_PER_BIT = CLK_FREQ_HZ / BAUD_RATE;

    // State enum: the four phases of transmitting one byte. The FSM is always in
    // exactly one of these states and moves between them on defined conditions:
    //   - IDLE      : doing nothing, tx wire held high, waiting for tx_start
    //   - START_BIT : driving the wire low for one bit period (the "0" start)
    //   - DATA_BITS : shifting out the 8 data bits, one per bit period
    //   - STOP_BIT  : driving the wire high for one bit period (the "1" stop)
    typedef enum logic [1:0] {
        IDLE,
        START_BIT,
        DATA_BITS,
        STOP_BIT
    } state_t;

    state_t state, state_next;

    // Internal registers:
    //   cycle_cnt  — counts clk cycles within the current bit (0 .. CYCLES_PER_BIT-1);
    //                tells you when one bit period has elapsed.
    //   bit_idx    — which of the 8 data bits is currently being sent (0 .. 7).
    //   data_shift — a latched copy of tx_data, so the caller can change tx_data
    //                after starting without corrupting the in-flight byte.
    logic [8:0] cycle_cnt;
    logic [2:0] bit_idx;
    logic [7:0] data_shift;

    // =========================================================================
    // State register (sequential). On every rising clock edge, update `state` to
    // `state_next`; on reset, force back to IDLE. This is the ONLY place `state`
    // is assigned.
    // =========================================================================
    always_ff @(posedge clk) begin
        if (!rst_n)  state <= IDLE;
        else         state <= state_next;
    end

    // =========================================================================
    // Cycle counter (sequential) — the "bit-period timer." Counts clk cycles so
    // we know when one bit period (CYCLES_PER_BIT) has elapsed. Resets to 0 on a
    // state change (fresh count per bit) and when it reaches its max.
    // =========================================================================
    always_ff @(posedge clk) begin
        if (!rst_n)
            cycle_cnt <= 0;
        else if (state != state_next)
            cycle_cnt <= 0;
        else if (cycle_cnt == CYCLES_PER_BIT - 1)
            cycle_cnt <= 0;
        else
            cycle_cnt <= cycle_cnt + 1;
    end

    // =========================================================================
    // Bit index counter (sequential) — tracks which of the 8 data bits we're on.
    // Advances once per completed bit period while in DATA_BITS; parked at 0 in
    // every other state so the next byte starts from bit 0.
    // =========================================================================
    always_ff @(posedge clk) begin
        if (!rst_n)
            bit_idx <= 0;
        else if (state != DATA_BITS)
            bit_idx <= 0;
        else if (cycle_cnt == CYCLES_PER_BIT - 1)
            bit_idx <= bit_idx + 1;
    end

    // =========================================================================
    // Latch the input byte (sequential). When a transmission starts (IDLE and
    // tx_start), snapshot tx_data into data_shift so a caller changing tx_data
    // mid-frame can't corrupt the in-flight byte.
    // =========================================================================
    always_ff @(posedge clk) begin
        if (!rst_n)
            data_shift <= 8'h00;
        else if (state == IDLE && tx_start)
            data_shift <= tx_data;
    end

    // =========================================================================
    // Next-state logic (combinational). Decides state_next from the current state
    // plus inputs; defaults to "stay put":
    //   - IDLE:      tx_start                          -> START_BIT
    //   - START_BIT: bit period done                   -> DATA_BITS
    //   - DATA_BITS: bit period done AND bit_idx == 7   -> STOP_BIT
    //   - STOP_BIT:  bit period done                   -> IDLE
    // =========================================================================
    always_comb begin
        state_next = state;
        case (state)
            IDLE:      if (tx_start) state_next = START_BIT;
            START_BIT: if (cycle_cnt == CYCLES_PER_BIT - 1) state_next = DATA_BITS;
            DATA_BITS: if (cycle_cnt == CYCLES_PER_BIT - 1 && bit_idx == 7) state_next = STOP_BIT;
            STOP_BIT:  if (cycle_cnt == CYCLES_PER_BIT - 1) state_next = IDLE;
        endcase
    end

    // =========================================================================
    // Output logic (combinational) — drives the tx wire based purely on state:
    //   - IDLE      -> 1 (idle high)
    //   - START_BIT -> 0 (start bit is always 0)
    //   - DATA_BITS -> the current data bit: data_shift[bit_idx]  (LSB first)
    //   - STOP_BIT  -> 1 (stop bit is always 1)
    // =========================================================================
    always_comb begin
        tx = 1'b1;
        case (state)
            IDLE:      tx = 1'b1;
            START_BIT: tx = 1'b0;
            DATA_BITS: tx = data_shift[bit_idx];
            STOP_BIT:  tx = 1'b1;
        endcase
    end

    // =========================================================================
    // Status outputs.
    //   tx_busy: HIGH whenever a frame is in flight (state != IDLE). Combinational.
    //   tx_done: a clean 1-cycle pulse as the frame finishes (STOP_BIT -> IDLE),
    //            registered so external logic gets a single "byte sent" handshake.
    // =========================================================================
    assign tx_busy = (state != IDLE);

    always_ff @(posedge clk) begin
        if (!rst_n)
            tx_done <= 1'b0;
        else
            tx_done <= (state == STOP_BIT && state_next == IDLE);
    end

endmodule
