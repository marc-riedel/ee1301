# Lecture 4: Introduction to Embedded Systems

## What are Embedded Systems?
Embedded systems are computer systems designed to perform specific tasks within larger mechanical or electrical systems. They are "embedded" as part of a complete device.

## Characteristics of Embedded Systems
- **Dedicated functionality**: Designed for specific tasks
- **Real-time operation**: Must respond within strict time constraints
- **Resource constraints**: Limited memory, processing power, and energy
- **Reliability**: Must operate continuously without failure
- **Cost-sensitive**: Often mass-produced

## Examples of Embedded Systems
### Consumer Electronics
- Smartphones and tablets
- Smart TVs and streaming devices
- Home appliances (washing machines, microwaves)
- Gaming consoles

### Automotive Systems
- Engine control units (ECU)
- Anti-lock braking systems (ABS)
- Airbag deployment systems
- Infotainment systems

### Industrial Applications
- Programmable logic controllers (PLC)
- Robotic control systems
- Manufacturing equipment
- HVAC control systems

### IoT Devices
- Smart home sensors
- Wearable fitness trackers
- Environmental monitoring stations
- Smart agriculture sensors

## Particle Platform Overview
The Particle platform provides cloud-connected development boards ideal for learning embedded systems and IoT development.

### Popular Particle Devices
- **Particle Photon**: Wi-Fi enabled, ARM Cortex M3
- **Particle Argon**: Wi-Fi + Bluetooth, ARM Cortex M4
- **Particle Boron**: Cellular + Wi-Fi + Bluetooth
- **Particle Electron**: Cellular connectivity

### Key Features
- **Cloud connectivity**: Built-in Wi-Fi/cellular
- **Over-the-air updates**: Update firmware remotely
- **Cloud functions**: Call device functions from anywhere
- **Cloud variables**: Monitor device state remotely
- **Event publishing**: Send data to cloud or other devices

## Basic Hardware Concepts

### Digital I/O
Digital pins can be configured as inputs or outputs with two states:
- **HIGH** (3.3V or 5V)
- **LOW** (0V or Ground)

```cpp
// Set pin D7 as output
pinMode(D7, OUTPUT);

// Turn LED on
digitalWrite(D7, HIGH);

// Turn LED off
digitalWrite(D7, LOW);

// Read digital input
int buttonState = digitalRead(D2);
```

### Analog I/O
Analog pins can read continuous voltage levels using an Analog-to-Digital Converter (ADC).

```cpp
// Read analog value (0-4095 on Particle devices)
int sensorValue = analogRead(A0);

// Convert to voltage (assuming 3.3V reference)
float voltage = sensorValue * (3.3 / 4095.0);

// Output PWM signal (0-255)
analogWrite(A5, 128);  // 50% duty cycle
```

### Serial Communication
Serial communication allows the microcontroller to communicate with computers or other devices.

```cpp
void setup() {
    Serial.begin(9600);  // Start serial at 9600 baud
    Serial.println("System starting...");
}

void loop() {
    Serial.print("Sensor reading: ");
    Serial.println(analogRead(A0));
    delay(1000);
}
```

## Programming Structure

### Setup Function
Runs once when the device starts or resets:
```cpp
void setup() {
    // Initialize pins
    pinMode(D7, OUTPUT);
    pinMode(A0, INPUT);
    
    // Start serial communication
    Serial.begin(9600);
    
    // Initialize sensors or other hardware
    Serial.println("Device initialized");
}
```

### Loop Function
Runs continuously after setup() completes:
```cpp
void loop() {
    // Read sensors
    int sensorValue = analogRead(A0);
    
    // Process data
    float temperature = convertToTemperature(sensorValue);
    
    // Control outputs
    controlLED(temperature);
    
    // Communicate
    Serial.println(temperature);
    
    // Wait before next iteration
    delay(1000);
}
```

## Timing and Delays

### Basic Delays
```cpp
delay(1000);        // Wait 1 second (blocking)
delayMicroseconds(500);  // Wait 500 microseconds
```

### Non-blocking Timing
```cpp
unsigned long previousMillis = 0;
const long interval = 1000;  // 1 second

void loop() {
    unsigned long currentMillis = millis();
    
    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        
        // Do something every second
        digitalWrite(D7, !digitalRead(D7));  // Toggle LED
    }
    
    // Other non-blocking code can run here
}
```

## Working with Sensors

### Temperature Sensor (TMP36)
```cpp
float readTemperature(int pin) {
    int rawValue = analogRead(pin);
    
    // Convert to voltage
    float voltage = rawValue * (3.3 / 4095.0);
    
    // TMP36: 10mV/°C, 500mV at 0°C
    float temperature = (voltage - 0.5) * 100.0;
    
    return temperature;
}
```

### Light Sensor (Photoresistor)
```cpp
int readLightLevel(int pin) {
    int rawValue = analogRead(pin);
    
    // Convert to percentage (0-100%)
    int lightPercent = map(rawValue, 0, 4095, 0, 100);
    
    return lightPercent;
}
```

### Push Button with Debouncing
```cpp
bool readButton(int pin) {
    static bool lastState = false;
    static unsigned long lastDebounceTime = 0;
    const unsigned long debounceDelay = 50;
    
    bool currentState = digitalRead(pin);
    
    if (currentState != lastState) {
        lastDebounceTime = millis();
    }
    
    if ((millis() - lastDebounceTime) > debounceDelay) {
        if (currentState != lastState) {
            lastState = currentState;
            return currentState;
        }
    }
    
    return false;  // No stable change detected
}
```

## Cloud Connectivity

### Publishing Events
```cpp
void publishSensorData() {
    float temperature = readTemperature(A0);
    int lightLevel = readLightLevel(A1);
    
    // Create JSON string
    String data = "{";
    data += "\"temperature\":" + String(temperature, 1) + ",";
    data += "\"light\":" + String(lightLevel);
    data += "}";
    
    // Publish to cloud
    Particle.publish("sensor_data", data, PRIVATE);
}
```

### Cloud Functions
```cpp
int setLED(String command) {
    if (command == "on") {
        digitalWrite(D7, HIGH);
        return 1;  // Success
    } else if (command == "off") {
        digitalWrite(D7, LOW);
        return 1;  // Success
    }
    
    return -1;  // Error
}

void setup() {
    pinMode(D7, OUTPUT);
    
    // Register cloud function
    Particle.function("led_control", setLED);
}
```

### Cloud Variables
```cpp
double currentTemperature = 0.0;
int deviceStatus = 0;

void setup() {
    // Register cloud variables
    Particle.variable("temperature", currentTemperature);
    Particle.variable("status", deviceStatus);
}

void loop() {
    // Update variables that can be read from the cloud
    currentTemperature = readTemperature(A0);
    deviceStatus = (currentTemperature > 0) ? 1 : 0;
    
    delay(1000);
}
```

## Common Embedded System Patterns

### State Machines
```cpp
enum SystemState {
    IDLE,
    MEASURING,
    ALERTING,
    SLEEPING
};

SystemState currentState = IDLE;

void stateMachine() {
    switch (currentState) {
        case IDLE:
            if (buttonPressed()) {
                currentState = MEASURING;
            }
            break;
            
        case MEASURING:
            takeMeasurement();
            if (measurementComplete()) {
                currentState = (isAlertCondition()) ? ALERTING : IDLE;
            }
            break;
            
        case ALERTING:
            flashAlertLED();
            if (alertAcknowledged()) {
                currentState = IDLE;
            }
            break;
            
        case SLEEPING:
            enterLowPowerMode();
            break;
    }
}
```

### Interrupt Handling
```cpp
volatile bool buttonPressed = false;

void buttonISR() {
    buttonPressed = true;
}

void setup() {
    pinMode(D2, INPUT_PULLUP);
    attachInterrupt(D2, buttonISR, FALLING);
}

void loop() {
    if (buttonPressed) {
        buttonPressed = false;
        Serial.println("Button was pressed!");
        // Handle button press
    }
    
    // Other tasks
}
```

## Best Practices for Embedded Programming

### 1. Power Management
```cpp
// Use sleep modes when possible
System.sleep(SLEEP_MODE_DEEP, 300);  // Sleep for 5 minutes

// Turn off unused peripherals
// Use efficient algorithms
```

### 2. Memory Management
```cpp
// Avoid dynamic memory allocation in loops
// Use const for constants
const int MAX_READINGS = 100;

// Prefer local variables over global when possible
```

### 3. Error Handling
```cpp
bool initializeSensor() {
    // Attempt to initialize sensor
    if (!sensor.begin()) {
        Serial.println("Sensor initialization failed!");
        return false;
    }
    return true;
}
```

### 4. Watchdog Timers
```cpp
void setup() {
    // Enable watchdog timer to recover from hangs
    System.enableWatchdog(60000);  // 60-second timeout
}

void loop() {
    // Pet the watchdog to prevent reset
    System.tickWatchdog();
    
    // Your main code here
}
```

## Laboratory Exercises

### Exercise 1: Blinking LED
Create a program that blinks an LED at different rates based on sensor input.

### Exercise 2: Temperature Monitor
Build a temperature monitoring system that sends alerts when thresholds are exceeded.

### Exercise 3: Data Logger
Create a system that logs sensor data to the cloud and can be controlled remotely.

## Key Takeaways
1. Embedded systems are specialized computers for specific tasks
2. Real-time constraints and resource limitations are key considerations
3. Digital and analog I/O form the basis of sensor interfaces
4. Non-blocking programming techniques improve system responsiveness
5. Cloud connectivity enables remote monitoring and control
6. State machines help organize complex system behavior

---
*Previous: [Lecture 3 - Programming Fundamentals](./lecture03_programming.md)*  
*Next: [Lecture 5 - Circuit Analysis Techniques](./lecture05_circuit_analysis.md)*