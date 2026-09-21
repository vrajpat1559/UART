# UART Transceiver (SystemVerilog)

A parameterized 8N1 UART transmitter and receiver, written from scratch in SystemVerilog and
verified with self-checking testbenches. Target platform is an Intel Cyclone 10 LP FPGA in
Quartus Prime; simulations run in Icarus Verilog / Questa.

## Status

- [x] Transmitter (`UART_TX.sv`): four-state FSM, cycle-accurate baud counter, parameterized `CLK_FREQ_HZ` / `BAUD_RATE`
- [x] TX self-checking testbench (`UART_TX_TB.sv`): 27 directed tests, all passing
- [x] Receiver (`UART_RX.sv`): two-flop synchronizer, oversampling with mid-bit sampling, start-bit detection
- [x] RX self-checking testbench (`UART_RX_TB.sv`)
- [x] Loopback testbench (`tb_loopback.sv`): TX driving RX, every byte checked
- [ ] Top-level module (`UART_top_down.sv`) wiring TX and RX to board I/O
- [ ] Timing constraints (`.sdc`) and pin assignments for the Cyclone 10 board
- [ ] Synthesize in Quartus and program the board
- [ ] Loopback test on hardware through a USB-serial adapter

## Files

| File | Purpose |
|------|---------|
| `UART_TX.sv` | Transmitter module |
| `UART_RX.sv` | Receiver module |
| `UART_top_down.sv` | Top-level module (in progress) |
| `UART_TX_TB.sv` | Transmitter testbench |
| `UART_RX_TB.sv` | Receiver testbench |
| `tb_loopback.sv` | End-to-end loopback testbench |
| `UART.qpf` / `UART.qsf` | Quartus project and settings |

## Running the simulations

Each testbench is self-contained and prints a pass/fail count at the end. With Icarus Verilog:

```bash
iverilog -g2012 -o tx_tb  UART_TX.sv UART_TX_TB.sv  && vvp tx_tb
iverilog -g2012 -o rx_tb  UART_RX.sv UART_RX_TB.sv  && vvp rx_tb
iverilog -g2012 -o loop   UART_TX.sv UART_RX.sv tb_loopback.sv && vvp loop
```

Defaults are a 50 MHz clock and 115200 baud; override the parameters at instantiation for other boards.
