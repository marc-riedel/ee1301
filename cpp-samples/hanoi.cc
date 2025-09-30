#include <iostream>
#include <cstdlib>
using namespace std;

void hanoi(int n, int a, int c, int b) {
    if (n == 1)
        cout << "Move disk from " << a << " to " << c << endl;
    else {
        hanoi(n - 1, a, b, c);
        cout << "Move disk from " << a << " to " << c << endl;
        hanoi(n - 1, b, c, a);
    }
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <num_disks>" << endl;
        return 1;
    }
    int n = atoi(argv[1]);
    hanoi(n, 1, 2, 3);
    return 0;
}

