# EE1301 - Introduction to Electrical Engineering

This repository contains comprehensive teaching materials for EE1301 - Introduction to Electrical Engineering, including sample code, embedded system projects, and detailed lecture notes.

## Repository Structure

### 📂 [cpp-samples/](./cpp-samples/)
Sample C++ programs demonstrating fundamental programming concepts for electrical engineering:

- **[hello_world.cpp](./cpp-samples/hello_world.cpp)** - Basic input/output and introduction to C++
- **[power_calculator.cpp](./cpp-samples/power_calculator.cpp)** - Electrical power calculations using Ohm's law
- **[data_analysis.cpp](./cpp-samples/data_analysis.cpp)** - Statistical analysis of voltage measurements using classes

### 📂 [particle-samples/](./particle-samples/)
Embedded system examples using Particle.io platform for IoT and microcontroller programming:

- **[led_blink.ino](./particle-samples/led_blink.ino)** - Basic digital output control
- **[analog_sensor.ino](./particle-samples/analog_sensor.ino)** - Analog-to-digital conversion and sensor reading
- **[temperature_monitor.ino](./particle-samples/temperature_monitor.ino)** - Complete IoT temperature monitoring system with cloud connectivity

### 📂 [lecture-notes/](./lecture-notes/)
Comprehensive lecture notes covering course fundamentals:

- **[Lecture 1: Introduction](./lecture-notes/lecture01_introduction.md)** - Course overview and electrical engineering basics
- **[Lecture 2: Ohm's Law and Basic Circuits](./lecture-notes/lecture02_ohms_law.md)** - Fundamental circuit analysis
- **[Lecture 3: Programming Fundamentals](./lecture-notes/lecture03_programming.md)** - C++ programming for engineers
- **[Lecture 4: Embedded Systems](./lecture-notes/lecture04_embedded_systems.md)** - Introduction to microcontrollers and IoT

## Course Overview

EE1301 provides students with foundational knowledge in:

- **Circuit Analysis**: Ohm's law, Kirchhoff's laws, series/parallel circuits
- **Programming**: C++ fundamentals, object-oriented programming, data analysis
- **Embedded Systems**: Microcontroller programming, sensor interfacing, IoT applications
- **Mathematical Tools**: Engineering mathematics and computational methods

## Getting Started

### Prerequisites
- Basic algebra and trigonometry
- No prior programming experience required

### Software Requirements
- C++ compiler (GCC, Visual Studio, or similar)
- Particle CLI or Particle Workbench (for embedded examples)
- Text editor or IDE (VS Code recommended)

### Hardware Requirements (for lab work)
- Particle Photon/Argon development board
- Breadboard and jumper wires
- Basic electronic components (resistors, LEDs, sensors)
- Multimeter

## Learning Path

1. **Start with Lecture Notes**: Begin with [Lecture 1](./lecture-notes/lecture01_introduction.md) for course overview
2. **Practice Programming**: Work through C++ samples in order of complexity
3. **Hands-on Projects**: Build the Particle.io embedded system examples
4. **Apply Knowledge**: Complete laboratory exercises and assignments

## Usage Instructions

### Running C++ Examples
```bash
# Compile and run a C++ program
g++ -o power_calculator cpp-samples/power_calculator.cpp
./power_calculator
```

### Working with Particle Examples
1. Install Particle CLI: `npm install -g particle-cli`
2. Login to your Particle account: `particle login`
3. Flash code to device: `particle flash [device_name] particle-samples/led_blink.ino`

## Contributing

This repository is designed for educational use. Students and instructors are welcome to:
- Report issues or suggest improvements
- Submit additional examples or exercises
- Enhance documentation and explanations

## Resources

- **Course Website**: [University course page]
- **Particle Documentation**: https://docs.particle.io/
- **C++ Reference**: https://cppreference.com/
- **Circuit Simulation**: Recommend Falstad or LTSpice

## License

Educational use only. Please respect copyright and academic integrity policies.

---

*For questions or support, contact the course instructor or teaching assistants.*
