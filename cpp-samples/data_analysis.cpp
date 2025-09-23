#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class VoltageData {
private:
    vector<double> measurements;
    string location;

public:
    VoltageData(string loc) : location(loc) {}
    
    void addMeasurement(double voltage) {
        measurements.push_back(voltage);
    }
    
    double getAverage() const {
        if (measurements.empty()) return 0.0;
        double sum = accumulate(measurements.begin(), measurements.end(), 0.0);
        return sum / measurements.size();
    }
    
    double getMax() const {
        if (measurements.empty()) return 0.0;
        return *max_element(measurements.begin(), measurements.end());
    }
    
    double getMin() const {
        if (measurements.empty()) return 0.0;
        return *min_element(measurements.begin(), measurements.end());
    }
    
    void displayStats() const {
        cout << "\n=== Voltage Statistics for " << location << " ===" << endl;
        cout << "Number of measurements: " << measurements.size() << endl;
        cout << "Average voltage: " << getAverage() << " V" << endl;
        cout << "Maximum voltage: " << getMax() << " V" << endl;
        cout << "Minimum voltage: " << getMin() << " V" << endl;
        cout << "Voltage range: " << (getMax() - getMin()) << " V" << endl;
    }
};

int main() {
    VoltageData lab_data("Lab Station 1");
    
    // Simulate some voltage measurements
    vector<double> sample_voltages = {5.12, 4.98, 5.05, 5.02, 4.97, 5.08, 5.01, 4.99};
    
    cout << "Adding voltage measurements..." << endl;
    for (double voltage : sample_voltages) {
        lab_data.addMeasurement(voltage);
        cout << "Measured: " << voltage << " V" << endl;
    }
    
    lab_data.displayStats();
    
    return 0;
}