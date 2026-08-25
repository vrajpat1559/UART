# CLAUDE.md — UART FPGA Project

## Summary

This is an **Intel/Altera Quartus Prime FPGA project** intended to implement a
**UART** (Universal Asynchronous Receiver/Transmitter) serial communication core.
As it currently stands, the project is a **skeleton only** — the Quartus project
scaffolding exists, but **no actual hardware design source has been added yet**.

## Project Overview

| Item | Value |
|------|-------|
| Tool | Quartus Prime 25.1 Standard Edition (Altera) |
| Target family | Cyclone V |
| Target device | `5CGXFC7C7F23C8` |
| Top-level entity | `UART` |
| Simulation tool | Questa Altera FPGA (Verilog) |
| Output directory | `output_files` |
| Created | Aug 21, 2026 |

### Files present

- `UART.qpf` — Quartus Project File (revision list only).
- `UART.qsf` — Quartus Settings File (device, tool, and global assignments).
- `db/` — Quartus internal database folder (currently empty).

### How it is meant to fit together

In a complete Quartus UART project you would expect:
1. **HDL source** (`UART.v` / `UART.sv` or `.vhd`) defining the `UART` top entity,
   typically split into a transmitter, a receiver, and a baud-rate generator.
2. **Pin/timing constraints** (`.sdc`) and pin assignments in the `.qsf`
   (clock, reset, TX, RX, and any board LEDs/switches).
3. A **testbench** for simulation in Questa.
4. Generated **output files** (`.sof`/`.pof`) after a successful compile.

None of items 1–4 exist yet.

## Weaknesses / Issues Found

1. **No design source at all.** There are no `.v`, `.sv`, `.vhd`, or `.bdf`
   files. The `.qsf` declares `TOP_LEVEL_ENTITY = UART`, but nothing defines
   that entity — the project cannot compile in its current state.

2. **`SOURCE_FILE` assignments point at the wrong things.** The `.qsf` lists
   the project's own `UART.qsf`, `UART.qpf`, a `UART.db_info`, and a
   `UART.quiproj.*.rdr.flock` **lock file** as source files, via relative paths
   back into `../../../Downloads/UART Project-.../`. These are Quartus
   bookkeeping/lock artifacts, **not HDL design files**, and the paths reach
   outside the project folder — a sign the project was extracted/copied out of a
   downloaded zip while its real sources were left behind.

3. **No timing constraints (`.sdc`).** UARTs are clock-driven; without an SDC
   file the design has no defined clock or timing closure, so timing results
   would be meaningless.

4. **No pin assignments.** Nothing maps `clk`, `reset`, `rx`, `tx` to physical
   device pins, so even a compiled design couldn't be deployed to a board.

5. **No testbench / simulation setup.** Questa is selected as the sim tool, but
   there is no stimulus to verify TX/RX behavior across baud rates.

6. **No version control or documentation.** The folder isn't a git repository,
   and there is no README describing intended baud rate, data/stop/parity bits,
   or clock frequency.

7. **Portability risk.** Storing an FPGA project inside a **OneDrive-synced**
   folder can cause Quartus lock-file (`.flock`) conflicts and slow/locked
   compiles when sync runs mid-build.

## Suggested Improvements / Next Steps

1. **Recover or author the HDL.** Either copy the real source files out of the
   original `Downloads/UART Project-.../` folder, or write the core fresh:
   - `uart_tx.v` — transmitter (shift-out, start/stop bit framing).
   - `uart_rx.v` — receiver (oversampling, start-bit detection, sampling).
   - `baud_gen.v` — baud-rate tick generator from the system clock.
   - `UART.v` — top-level wiring the three together to the top-level ports.
2. **Fix the `.qsf` source list.** Remove the bogus `SOURCE_FILE` entries that
   reference `.flock`/`.db_info`/`.qsf`/`.qpf`, and add proper
   `VERILOG_FILE`/`SYSTEMVERILOG_FILE` (or `VHDL_FILE`) assignments for the
   real design files, kept **inside** the project folder.
3. **Add a constraints file** (`UART.sdc`) defining the input clock and
   any I/O timing.
4. **Add pin assignments** for `clk`, `reset`, `rx`, `tx` matching your dev
   board (e.g. a Cyclone V GX board).
5. **Add a testbench** (`UART_tb.v`) and a simulation run so behavior is
   verified before hardware programming.
6. **Add a README** documenting the parameters: system clock frequency, target
   baud rate, data bits, parity, and stop bits.
7. **Move the project out of OneDrive** (or pause sync during builds) and put it
   under **git** to track changes and avoid sync-induced lock conflicts.

---
*Note: This document reflects the project as an empty/skeleton state. Once real
HDL sources are added, update the Overview and remove the resolved weaknesses.*
