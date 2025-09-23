#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "Hello, EE1301 Students!" << endl;
    cout << "Welcome to Introduction to Electrical Engineering" << endl;
    
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    
    cout << "Hello, " << name << "! Let's learn some engineering!" << endl;
    
    return 0;
}