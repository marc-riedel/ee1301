#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Calculate power in electrical circuits
    double voltage, current, resistance;
    
    cout << "=== Electrical Power Calculator ===" << endl;
    cout << "Enter voltage (V): ";
    cin >> voltage;
    
    cout << "Enter current (A): ";
    cin >> current;
    
    // Calculate power using P = V * I
    double power_vi = voltage * current;
    
    // Calculate resistance using R = V / I
    resistance = voltage / current;
    
    // Calculate power using P = V^2 / R
    double power_vr = (voltage * voltage) / resistance;
    
    // Calculate power using P = I^2 * R
    double power_ir = current * current * resistance;
    
    cout << fixed << setprecision(2);
    cout << "\n=== Results ===" << endl;
    cout << "Voltage: " << voltage << " V" << endl;
    cout << "Current: " << current << " A" << endl;
    cout << "Resistance: " << resistance << " Ω" << endl;
    cout << "Power (P=VI): " << power_vi << " W" << endl;
    cout << "Power (P=V²/R): " << power_vr << " W" << endl;
    cout << "Power (P=I²R): " << power_ir << " W" << endl;
    
    return 0;
}