/*
 * Basic LED Blink Example for Particle Photon/Argon
 * EE1301 - Introduction to Electrical Engineering
 * 
 * This program demonstrates basic digital output control
 * by blinking the built-in LED on the Particle device.
 */

// Define the LED pin (built-in LED on most Particle devices)
int led = D7;

void setup() {
    // Set the LED pin as an output
    pinMode(led, OUTPUT);
    
    // Optional: Start serial communication for debugging
    Serial.begin(9600);
    Serial.println("LED Blink Example Started");
}

void loop() {
    // Turn the LED on
    digitalWrite(led, HIGH);
    Serial.println("LED ON");
    
    // Wait for 1 second
    delay(1000);
    
    // Turn the LED off
    digitalWrite(led, LOW);
    Serial.println("LED OFF");
    
    // Wait for 1 second
    delay(1000);
}