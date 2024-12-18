#include <cmath>
#include <iostream>
using namespace std;

int main() {
    double L = 0, a;
    cin >> a;
    double U = a, x = (L + U) / 2;

    while (fabs(a - pow(10, x)) > (pow(10, -10) * max(a, pow(10, x))))
    // if sqrt(a);a-> use x^2 then log10 a; a -> use 10^x
    {
        if (pow(10, x) > a) {
            U = x; // x turn into U
        } else if (pow(10, x) < a) {
            L = x;
        }
        x = (L + U) / 2;
    }
    cout << x;
}