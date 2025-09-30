# EE 1301 — Lecture 4 (9/15–9/19): Memory, Variables, Datatypes, Assignment, Operators

## Learning Objectives
- Map variables to memory and reason about sizes/addresses.
- Pick correct integer/floating types; understand overflow/precision.
- Use assignment, compound ops, and precedence intentionally.

## Memory Model (mental picture)
- **RAM** is bytes with addresses; a 32‑bit `int` usually spans 4 bytes.
- A variable name is a handle to an address; initialization prevents garbage.
- Stack vs heap exists; for now, think “locals live on the stack”.

## Sizes & Ranges (typical, not guaranteed)
- `char` 1B (−128…127 or 0…255)
- `short` 2B (−32,768…32,767)
- `int` 4B (≈±2.1e9)
- `long` 8B on many 64‑bit platforms
- `float` 4B (≈7 digits), `double` 8B (≈16 digits)  
Use `sizeof(type)` if you need facts on your compiler.

## Assignment & Compound Ops
```c
int a = 5;
int b = a;     // copy
b += 3;        // 8
b *= 2;        // 16
```
- It’s a **copy**, not a link. Updating `b` doesn’t change `a`.

## Precedence and Parentheses
```c
int a = 5, b = 2, r;
r = a + b * 3;        // 11 (* before +)
r = (a + b) * 3;      // 21 (forced)
```

## Integer vs Floating Arithmetic
```c
int n = 5, d = 2;
double q1 = n / d;          // 2 (int division, then promoted)
double q2 = (double)n / d;  // 2.5 (good)
```

## Bitwise (preview you’ll need later)
```c
unsigned x = 0b10110100;     // GCC/Clang extension; or use hex 0xB4
unsigned m = 0x0F;
unsigned low = x & m;        // mask low nibble
unsigned hi  = (x >> 4) & m; // high nibble
```

## Overflow: Not a Joke
```c
int big = 2'000'000'000;
int sum = big + big;   // UB or wrap — don’t do this
```
- Signed overflow is undefined in C. Pick `long long` or checked libs if needed.

## Summary
Memory is concrete: bytes and addresses. Types define layout and meaning. Control precedence with parentheses, and respect integer vs float behavior. Write code that’s explicit about intent.