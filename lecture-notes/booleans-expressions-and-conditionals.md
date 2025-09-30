# EE 1301 — Lecture 5 (9/23): Booleans, Expressions, and Conditionals

## Learning Objectives
- Use `bool` cleanly; know 0=false, non‑zero=true semantics.
- Build/negate complex predicates with `&&`, `||`, `!` (short‑circuit).
- Write robust `if / else if / else` logic with tidy braces.

## Boolean Basics (C)
```c
#include <stdbool.h>

bool ready = false;
if (!ready)
{
    ready = true;
}
```
- Without `<stdbool.h>`, `int` works: 0=false, non‑zero=true. Prefer `bool` for clarity.

## Truth Tables (quick)
- AND: T∧T=T; otherwise F.
- OR: F∨F=F; otherwise T.
- NOT: !T=F; !F=T.

## Short‑Circuit Patterns
```c
if (ptr != NULL && *ptr > 0)
{
    /* safe: RHS only runs when ptr != NULL */
}
```

## De Morgan (simplify/invert conditions)
- `!(A && B)` ↔ `!A || !B`
- `!(A || B)` ↔ `!A && !B`

## Examples
**Leap Year**
```c
#include <stdbool.h>

bool is_leap(int year)
{
    if ((year % 400) == 0)
    {
        return true;
    }
    else if ((year % 100) == 0)
    {
        return false;
    }
    else if ((year % 4) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
```
**Range Check**
```c
int x = 57;
if (x >= 1 && x <= 100)
{
    /* in range */
}
else
{
    /* out of range */
}
```

## Anti‑Patterns (skip them)
- Assignments in conditions (`if (x = 0)`) — just no.
- Deeply nested `if`s where a guard clause is clearer.
- Relying on side effects inside boolean expressions.

## Summary
Booleans express intent. Write conditions that are obvious at a glance, lean on short‑circuiting, and use braces on their own lines for maintainability.