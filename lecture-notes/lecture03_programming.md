# Lecture 3: Programming Fundamentals for Engineers

## Why Programming in Electrical Engineering?
Modern electrical engineering relies heavily on programming for:
- Circuit simulation and analysis
- Data acquisition and processing
- Embedded system control
- Signal processing algorithms
- Automation and control systems

## C++ for Engineers

### Basic Data Types
```cpp
int voltage = 12;           // Integer for whole numbers
double current = 2.5;       // Double for decimal numbers
float resistance = 4.7f;    // Float for smaller decimal numbers
bool isOn = true;          // Boolean for true/false states
char grade = 'A';          // Character for single letters
string name = "Circuit1";   // String for text
```

### Engineering Calculations
```cpp
#include <iostream>
#include <cmath>

// Calculate impedance in AC circuits
double calculateImpedance(double resistance, double reactance) {
    return sqrt(resistance * resistance + reactance * reactance);
}

// Convert degrees to radians
double degreesToRadians(double degrees) {
    return degrees * M_PI / 180.0;
}
```

### Arrays for Data Sets
```cpp
// Store multiple voltage measurements
double voltages[10] = {5.1, 4.9, 5.0, 5.2, 4.8, 5.1, 5.0, 4.9, 5.2, 5.0};

// Calculate average voltage
double sum = 0.0;
for (int i = 0; i < 10; i++) {
    sum += voltages[i];
}
double average = sum / 10.0;
```

### Vectors for Dynamic Data
```cpp
#include <vector>
#include <algorithm>

vector<double> sensorReadings;

// Add new reading
sensorReadings.push_back(3.14);

// Find maximum reading
double maxReading = *max_element(sensorReadings.begin(), sensorReadings.end());

// Sort readings
sort(sensorReadings.begin(), sensorReadings.end());
```

## Object-Oriented Programming for Engineering

### Classes for Circuit Components
```cpp
class Resistor {
private:
    double resistance;  // in Ohms
    double tolerance;   // percentage
    
public:
    Resistor(double r, double tol = 5.0) : resistance(r), tolerance(tol) {}
    
    double getResistance() const { return resistance; }
    double getTolerance() const { return tolerance; }
    
    double getPower(double current) const {
        return current * current * resistance;
    }
    
    double getVoltage(double current) const {
        return current * resistance;
    }
};
```

### Using the Resistor Class
```cpp
int main() {
    Resistor r1(1000.0, 1.0);  // 1kΩ ±1%
    
    double current = 0.01;  // 10mA
    
    cout << "Resistance: " << r1.getResistance() << " Ω" << endl;
    cout << "Voltage drop: " << r1.getVoltage(current) << " V" << endl;
    cout << "Power dissipated: " << r1.getPower(current) << " W" << endl;
    
    return 0;
}
```

## File I/O for Data Logging
```cpp
#include <fstream>

// Write sensor data to file
void logSensorData(const vector<double>& data, const string& filename) {
    ofstream file(filename);
    
    file << "Time,Voltage" << endl;  // CSV header
    
    for (size_t i = 0; i < data.size(); i++) {
        file << i << "," << data[i] << endl;
    }
    
    file.close();
}

// Read data from file
vector<double> readSensorData(const string& filename) {
    vector<double> data;
    ifstream file(filename);
    string line;
    
    getline(file, line);  // Skip header
    
    while (getline(file, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != string::npos) {
            double voltage = stod(line.substr(commaPos + 1));
            data.push_back(voltage);
        }
    }
    
    return data;
}
```

## Error Handling
```cpp
double safeDivision(double numerator, double denominator) {
    if (denominator == 0.0) {
        cerr << "Error: Division by zero!" << endl;
        return 0.0;  // or throw an exception
    }
    return numerator / denominator;
}

// Calculate current with error checking
double calculateCurrent(double voltage, double resistance) {
    if (resistance <= 0.0) {
        cerr << "Error: Invalid resistance value!" << endl;
        return 0.0;
    }
    return voltage / resistance;
}
```

## Functions for Engineering Calculations
```cpp
// Convert between units
double milliAmpsToAmps(double milliAmps) {
    return milliAmps / 1000.0;
}

double wattsToMilliwatts(double watts) {
    return watts * 1000.0;
}

// Engineering notation
string toEngineering(double value, const string& unit) {
    if (value >= 1e9) {
        return to_string(value / 1e9) + " G" + unit;
    } else if (value >= 1e6) {
        return to_string(value / 1e6) + " M" + unit;
    } else if (value >= 1e3) {
        return to_string(value / 1e3) + " k" + unit;
    } else if (value >= 1.0) {
        return to_string(value) + " " + unit;
    } else if (value >= 1e-3) {
        return to_string(value * 1e3) + " m" + unit;
    } else if (value >= 1e-6) {
        return to_string(value * 1e6) + " μ" + unit;
    } else {
        return to_string(value * 1e9) + " n" + unit;
    }
}
```

## Best Practices for Engineering Code

### 1. Use Meaningful Variable Names
```cpp
// Good
double supplyvoltage = 5.0;
double loadCurrent = 0.1;
double powerDissipation = supplyvoltage * loadCurrent;

// Bad
double v = 5.0;
double i = 0.1;
double p = v * i;
```

### 2. Add Comments for Complex Calculations
```cpp
// Calculate the time constant for an RC circuit
// τ = R × C (in seconds)
double timeConstant = resistance * capacitance;

// Calculate the cutoff frequency (-3dB point)
// fc = 1 / (2π × R × C)
double cutoffFrequency = 1.0 / (2.0 * M_PI * resistance * capacitance);
```

### 3. Use Constants
```cpp
const double PI = 3.14159265359;
const double BOLTZMANN_CONSTANT = 1.380649e-23;  // J/K
const double ELEMENTARY_CHARGE = 1.602176634e-19; // C
```

## Programming Exercises

### Exercise 1: Voltage Divider Calculator
Write a program that calculates the output voltage of a voltage divider circuit.

### Exercise 2: Parallel Resistance Calculator
Create a function that calculates the equivalent resistance of any number of parallel resistors.

### Exercise 3: Data Analysis Tool
Write a program that reads voltage measurements from a file and calculates statistics (mean, standard deviation, min, max).

## Connection to Lab Work
- Use programming to analyze experimental data
- Automate repetitive calculations
- Validate theoretical results with simulations
- Control instruments programmatically

## Key Takeaways
1. Programming is essential for modern electrical engineering
2. C++ provides powerful tools for engineering calculations
3. Object-oriented programming helps organize complex systems
4. File I/O enables data logging and analysis
5. Good programming practices improve code reliability

---
*Previous: [Lecture 2 - Ohm's Law](./lecture02_ohms_law.md)*  
*Next: [Lecture 4 - Embedded Systems](./lecture04_embedded_systems.md)*