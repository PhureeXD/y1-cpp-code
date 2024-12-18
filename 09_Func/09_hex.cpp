#include <iostream>
using namespace std;

string dec2hex(int d) {
    if (d < 10) return to_string(d);
    if (d < 12) return (d == 10 ? "A" : "B");
    if (d < 14) return (d == 12 ? "C" : "D");
    if (d < 16) return (d == 14 ? "E" : "F");
    return dec2hex(d / 16) + dec2hex(d % 16);
}

int main() {
    int d;
    while (cin >> d) {
        cout << d << " -> " << dec2hex(d) << endl;
    }
}