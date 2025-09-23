/*
 * Analog Sensor Reading Example for Particle Photon/Argon
 * EE1301 - Introduction to Electrical Engineering
 * 
 * This program reads analog values from a sensor (like a potentiometer
 * or temperature sensor) and demonstrates ADC functionality.
 */

// Define analog input pin
int sensorPin = A0;
int ledPin = D7;

// Variables to store sensor data
int sensorValue = 0;
float voltage = 0.0;

void setup() {
    // Initialize serial communication
    Serial.begin(9600);
    
    // Set LED as output for visual feedback
    pinMode(ledPin, OUTPUT);
    
    // Configure analog pin (usually not needed, but good practice)
    pinMode(sensorPin, INPUT);
    
    Serial.println("Analog Sensor Reading Started");
    Serial.println("Sensor Pin: A0");
    Serial.println("Reference Voltage: 3.3V");
    Serial.println("ADC Resolution: 12-bit (0-4095)");
    Serial.println("------------------------");
}

void loop() {
    // Read the analog value (0-4095 for 12-bit ADC)
    sensorValue = analogRead(sensorPin);
    
    // Convert to voltage (assuming 3.3V reference)
    voltage = sensorValue * (3.3 / 4095.0);
    
    // Print the results
    Serial.print("Raw ADC Value: ");
    Serial.print(sensorValue);
    Serial.print(" | Voltage: ");
    Serial.print(voltage, 3);  // 3 decimal places
    Serial.println(" V");
    
    // Visual feedback: LED brightness based on sensor value
    // Map sensor value (0-4095) to PWM range (0-255)
    int brightness = map(sensorValue, 0, 4095, 0, 255);
    analogWrite(ledPin, brightness);
    
    // Publish to Particle Cloud (optional)
    if (millis() % 10000 == 0) {  // Every 10 seconds
        Particle.publish("sensor_reading", String(voltage) + "V");
    }
    
    // Wait before next reading
    delay(500);
}