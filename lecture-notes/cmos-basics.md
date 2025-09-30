# EE 1301 — Lecture 1 (9/8): CMOS Basics — NMOS/PMOS, Inverter, NAND

## Learning Objectives
- Distinguish NMOS vs PMOS behavior and their on/off conditions.
- Explain pull-up (PMOS) and pull-down (NMOS) networks.
- Derive a CMOS inverter (NOT) and a 2-input NAND from transistor networks.
- Read and produce truth tables for NOT and NAND.

## Key Concepts
- **CMOS**: Complementary MOSFET technology using PMOS (pull-up) and NMOS (pull-down).
- **NMOS**: On when gate=1 → conducts to **GND**; Off when gate=0.
- **PMOS**: On when gate=0 → conducts to **VDD**; Off when gate=1.
- **Static power** (ideal CMOS): ~0 in steady states; dynamic power on transitions.

## CMOS Inverter (NOT)
**Behavior**: Out = ¬In.  
**Network**: PMOS up, NMOS down; gates tied to the same input.

```
 VDD
  │
 ┌┴┐  PMOS (on when In=0)
 │ │
 └┬┘───┐
  │    │  Out
 ┌┴┐   │
 │ │   │  NMOS (on when In=1)
 └┬┘───┘
  │
 GND
```

**Truth Table (Inverter)**

| In | Out |
|---:|:---:|
| 0  |  1  |
| 1  |  0  |

**Why it works**: If In=0 → PMOS on (pulls Out→VDD), NMOS off. If In=1 → PMOS off, NMOS on (pulls Out→GND). Only one network conducts in steady state → low static power.

## Two‑Input NAND (Y = ¬(A·B))
**PMOS (pull‑up)**: parallel (any 0 on input connects Out→VDD).  
**NMOS (pull‑down)**: series (both A=1 and B=1 to connect Out→GND).

```
 VDD
  │
 ┌┴┐ PMOS(A)
 │ │───────┐
 └┬┘       │
  │   ┌┴┐  │
  └───│ │──┘  PMOS(B) in parallel
      └┬┘
       │
      Out
       │
      ┌┬┐  NMOS(A) in series
      │ │
      └┬┘
       │
      ┌┬┐  NMOS(B)
      │ │
      └┬┘
       │
      GND
```

**Truth Table (NAND)**

| A | B | Y=¯(A·B) |
|:-:|:-:|:--------:|
| 0 | 0 |    1     |
| 0 | 1 |    1     |
| 1 | 0 |    1     |
| 1 | 1 |    0     |

**Design Rules (mental model)**
- Build pull‑down for the positive logic expression; mirror (De Morgan) for pull‑up.
- NAND/NOR are **universal** → you can build any logic with them + inverters.
- Keep inputs only on **gates** (no driving source/drain directly).

## Quick Check
1. Why are PMOS devices placed on the pull‑up network?
2. For a 3‑input NAND, how do you arrange PMOS/NMOS?
3. What input(s) minimize dynamic power on an inverter toggle? (Hint: switching activity.)

## Summary
CMOS pairs PMOS/NMOS so only one network conducts at DC. The inverter and NAND show the pattern: PMOS parallel ↔ NMOS series for NAND. This template scales to complex gates and underpins standard‑cell logic.