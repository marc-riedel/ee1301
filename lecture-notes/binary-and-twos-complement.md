# EE 1301 — Lecture 2 (9/10): Counting in Binary & Two’s Complement

## Learning Objectives
- Convert between decimal, binary, and hex.
- Count and add in binary, track carries.
- Encode negative integers with two’s complement; know range/overflow.

## Key Concepts
- **Place value (base‑2)**: bit i has weight 2^i. Example: 100101₂ = 32+4+1 = 37₁₀.
- **Hex**: compact base‑16; every 4 bits ↔ 1 hex digit.
- **Two’s complement (N bits)**: range = −2^{N−1} … +2^{N−1}−1.

## Binary Counting (4‑bit example)
0000, 0001, 0010, 0011, 0100, 0101, 0110, 0111, 1000, … (carry on 1111→0000 with overflow).

**Increment Algorithm (LSB→MSB)**
1. Start at bit 0.  
2. If bit==0 → set to 1 and **stop**.  
3. If bit==1 → set to 0 and carry to next bit; repeat.

## Conversions
- **Decimal → Binary**: repeated /2, collect remainders (LSB first).
- **Binary → Decimal**: sum of weights where bit=1.
- **Binary ↔ Hex**: group in 4s (pad left with zeros if needed).

## Two’s Complement
**Negation** (N bits): invert bits, add 1.  
Example (8‑bit): +5 = 0000 0101 → invert 1111 1010 → +1 = 1111 1011 = −5.

**Ranges**
- 8‑bit: −128 … +127
- 16‑bit: −32768 … +32767
- All‑ones (111…1) = −1; 1000…0 = most negative (no +ve counterpart).

**Overflow Reality Check**
0111 1111 (127) + 0000 0001 (1) = 1000 0000 (−128) → signed overflow (wrap).

## Worked Examples
- **Binary add**: 0101₂ (5) + 0110₂ (6) = 1011₂ (11).  
- **Sign‑magnitude to two’s**: −13 (8‑bit) → +13=0000 1101 → inv=1111 0010 → +1=1111 0011.

## Pseudocode Utilities
```text
# two's complement negate (N-bit)
function negate_nbit(x, N)
{
    mask = (1 << N) - 1
    return ((~x) & mask) + 1 & mask
}
```

## Summary
Binary is just place‑value with base 2. Two’s complement encodes negatives so the **same adder** handles add/sub; overflow wraps modulo 2^N. Know the ranges and the invert‑and‑add‑1 rule.