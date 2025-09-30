# EE 1301 — Lecture 3 (9/12): Intro Programming — Variables, I/O, Operators, Conditionals

## Learning Objectives
- Declare/initialize variables; choose types.
- Perform console I/O.
- Use arithmetic, relational, logical operators.
- Control flow with `if / else if / else` using clean brace style.

## Variables & Types (C)
```c
#include <stdio.h>

int main(void)
{
    int counter = 10;      // 32-bit typical
    double ratio = 3.5;    // 64-bit IEEE-754
    char grade = 'B';      // 8-bit

    printf("counter=%d ratio=%.2f grade=%c\n", counter, ratio, grade);
    return 0;
}
```
- Choose the **smallest** type that safely covers the range; avoid silent overflow.

## Console I/O (C)
```c
#include <stdio.h>

int main(void)
{
    int x;
    printf("Enter an integer: ");
    if (scanf("%d", &x) == 1)
    {
        printf("You entered %d\n", x);
    }
    else
    {
        printf("Invalid input.\n");
    }
    return 0;
}
```

## Operators (C)
- **Arithmetic**: `+ - * / %` (beware: `5/2==2` for ints).
- **Assignment**: `=, +=, -=, *=, /=, %=`
- **Relational**: `== != < <= > >=` → yields 0/1.
- **Logical**: `&& || !` (short‑circuit).

```c
int a = 5, b = 2;
int r1 = a + b * 3;      // 11
int r2 = (a + b) * 3;    // 21
int isOdd = (a % 2 == 1); // 1
int between = (a > 0 && a < 10); // 1
```

## Conditionals (brace-on-own-line style)
```c
int x = 7;

if (x % 2 == 0)
{
    printf("even\n");
}
else
{
    printf("odd\n");
}
```

```c
int score = 86;
if (score >= 90)
{
    printf("A\n");
}
else if (score >= 80)
{
    printf("B\n");
}
else if (score >= 70)
{
    printf("C\n");
}
else
{
    printf("F\n");
}
```

## Pitfalls (tell-it-like-it-is)
- `=` vs `==` bugs in `if`. Use warnings and read them.
- Integer division surprises; cast if you need real results.
- Don’t chain too-clever expressions; prioritize clarity.

## Summary
Master variables, I/O, operators, and straight‑shooting `if` logic. This is the backbone for everything you’ll code next.