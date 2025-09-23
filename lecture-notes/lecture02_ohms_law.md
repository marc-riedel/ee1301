# Lecture 2: Ohm's Law and Basic Circuits

## Ohm's Law
Ohm's Law is one of the most fundamental principles in electrical engineering, relating voltage, current, and resistance.

### The Mathematical Relationship
**V = I × R**

Where:
- **V** = Voltage (measured in Volts, V)
- **I** = Current (measured in Amperes, A)
- **R** = Resistance (measured in Ohms, Ω)

### Alternative Forms
From the basic equation V = IR, we can derive:
- **I = V / R** (Current equals voltage divided by resistance)
- **R = V / I** (Resistance equals voltage divided by current)

## Power Calculations
Power is the rate of energy consumption or generation in a circuit.

### Power Formulas
- **P = V × I** (Power equals voltage times current)
- **P = I² × R** (Power equals current squared times resistance)
- **P = V² / R** (Power equals voltage squared divided by resistance)

Where:
- **P** = Power (measured in Watts, W)

## Circuit Elements

### Resistors
- **Purpose**: Limit current flow and create voltage drops
- **Symbol**: Zigzag line or rectangle
- **Color codes**: Used to identify resistance values
- **Types**: Fixed, variable (potentiometers)

### Voltage Sources
- **DC Sources**: Batteries, power supplies
- **AC Sources**: Wall outlets, generators
- **Symbol**: Circle with + and - terminals

### Current Sources
- **Purpose**: Provide constant current regardless of load
- **Less common in introductory circuits**
- **Symbol**: Circle with arrow

## Series Circuits
In a series circuit, components are connected end-to-end in a single path.

### Series Circuit Properties
1. **Current**: Same through all components
   - I₁ = I₂ = I₃ = I_total
2. **Voltage**: Divides across components
   - V_total = V₁ + V₂ + V₃
3. **Resistance**: Adds up
   - R_total = R₁ + R₂ + R₃

### Voltage Divider Rule
For two resistors in series:
**V_out = V_in × (R₂ / (R₁ + R₂))**

## Parallel Circuits
In a parallel circuit, components are connected across common points.

### Parallel Circuit Properties
1. **Voltage**: Same across all components
   - V₁ = V₂ = V₃ = V_total
2. **Current**: Divides among branches
   - I_total = I₁ + I₂ + I₃
3. **Resistance**: Reciprocal formula
   - 1/R_total = 1/R₁ + 1/R₂ + 1/R₃

### Current Divider Rule
For two resistors in parallel:
**I₁ = I_total × (R₂ / (R₁ + R₂))**

## Example Problems

### Example 1: Simple Series Circuit
Given: V = 12V, R₁ = 2Ω, R₂ = 4Ω

Find: I, P_total

**Solution:**
- R_total = R₁ + R₂ = 2Ω + 4Ω = 6Ω
- I = V / R_total = 12V / 6Ω = 2A
- P_total = V × I = 12V × 2A = 24W

### Example 2: Simple Parallel Circuit
Given: V = 9V, R₁ = 3Ω, R₂ = 6Ω

Find: I_total, P_total

**Solution:**
- 1/R_total = 1/3 + 1/6 = 2/6 + 1/6 = 3/6 = 1/2
- R_total = 2Ω
- I_total = V / R_total = 9V / 2Ω = 4.5A
- P_total = V × I_total = 9V × 4.5A = 40.5W

## Laboratory Exercise
Build the circuits from Examples 1 and 2 using:
- Breadboard
- Resistors
- DC power supply
- Multimeter

Measure and compare theoretical vs. actual values.

## Programming Connection
The power calculator C++ program demonstrates these concepts:
```cpp
// Calculate power using different formulas
double power_vi = voltage * current;
double power_vr = (voltage * voltage) / resistance;
double power_ir = current * current * resistance;
```

## Key Takeaways
1. Ohm's Law is fundamental to circuit analysis
2. Power can be calculated using three different formulas
3. Series circuits: current constant, voltage divides
4. Parallel circuits: voltage constant, current divides
5. Understanding these basics enables complex circuit analysis

---
*Previous: [Lecture 1 - Introduction](./lecture01_introduction.md)*  
*Next: [Lecture 3 - Programming Fundamentals](./lecture03_programming.md)*