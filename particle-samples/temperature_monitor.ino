/*
 * Temperature Monitoring System for Particle Photon/Argon
 * EE1301 - Introduction to Electrical Engineering
 * 
 * This program reads temperature from a sensor, processes the data,
 * and demonstrates cloud connectivity and data logging.
 */

#include "math.h"

// Pin definitions
int tempSensorPin = A1;
int alertLedPin = D2;
int statusLedPin = D7;

// Temperature thresholds (in Celsius)
float tempThresholdLow = 18.0;   // Below this: too cold
float tempThresholdHigh = 25.0;  // Above this: too hot

// Variables for temperature calculation
float temperature = 0.0;
int rawValue = 0;

// Timing variables
unsigned long lastReading = 0;
unsigned long readingInterval = 2000;  // Read every 2 seconds

void setup() {
    Serial.begin(9600);
    
    // Configure pins
    pinMode(alertLedPin, OUTPUT);
    pinMode(statusLedPin, OUTPUT);
    pinMode(tempSensorPin, INPUT);
    
    // Register cloud functions and variables
    Particle.function("setThresholds", setThresholds);
    Particle.variable("temperature", temperature);
    Particle.variable("status", getStatusString);
    
    Serial.println("Temperature Monitoring System Started");
    Serial.println("Low Threshold: " + String(tempThresholdLow) + "°C");
    Serial.println("High Threshold: " + String(tempThresholdHigh) + "°C");
    
    // Indicate system ready
    digitalWrite(statusLedPin, HIGH);
}

void loop() {
    // Check if it's time for a new reading
    if (millis() - lastReading >= readingInterval) {
        readTemperature();
        checkThresholds();
        publishData();
        lastReading = millis();
    }
    
    // Blink status LED to show system is alive
    if (millis() % 1000 < 100) {
        digitalWrite(statusLedPin, HIGH);
    } else {
        digitalWrite(statusLedPin, LOW);
    }
}

void readTemperature() {
    rawValue = analogRead(tempSensorPin);
    
    // Convert ADC reading to voltage
    float voltage = rawValue * (3.3 / 4095.0);
    
    // Convert voltage to temperature (assuming TMP36 sensor)
    // TMP36: 10mV/°C with 500mV offset at 0°C
    temperature = (voltage - 0.5) * 100.0;
    
    Serial.print("Raw: ");
    Serial.print(rawValue);
    Serial.print(" | Voltage: ");
    Serial.print(voltage, 3);
    Serial.print("V | Temperature: ");
    Serial.print(temperature, 1);
    Serial.println("°C");
}

void checkThresholds() {
    if (temperature < tempThresholdLow || temperature > tempThresholdHigh) {
        // Temperature out of range - flash alert LED
        digitalWrite(alertLedPin, HIGH);
        delay(100);
        digitalWrite(alertLedPin, LOW);
        
        if (temperature < tempThresholdLow) {
            Serial.println("ALERT: Temperature too low!");
        } else {
            Serial.println("ALERT: Temperature too high!");
        }
    } else {
        digitalWrite(alertLedPin, LOW);
    }
}

void publishData() {
    // Create JSON string with sensor data
    String data = "{";
    data += "\"temperature\":" + String(temperature, 2) + ",";
    data += "\"raw_value\":" + String(rawValue) + ",";
    data += "\"status\":\"" + getStatusString() + "\"";
    data += "}";
    
    Particle.publish("temp_data", data, PRIVATE);
}

String getStatusString() {
    if (temperature < tempThresholdLow) {
        return "COLD";
    } else if (temperature > tempThresholdHigh) {
        return "HOT";
    } else {
        return "NORMAL";
    }
}

// Cloud function to update thresholds remotely
int setThresholds(String command) {
    // Expected format: "low,high" e.g., "18.0,25.0"
    int commaIndex = command.indexOf(',');
    
    if (commaIndex > 0) {
        tempThresholdLow = command.substring(0, commaIndex).toFloat();
        tempThresholdHigh = command.substring(commaIndex + 1).toFloat();
        
        Serial.println("Thresholds updated:");
        Serial.println("Low: " + String(tempThresholdLow) + "°C");
        Serial.println("High: " + String(tempThresholdHigh) + "°C");
        
        return 1;  // Success
    }
    
    return -1;  // Error
}