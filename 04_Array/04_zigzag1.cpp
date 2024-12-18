#include <cmath>
#include <iostream>
using namespace std;

int main() {
    double x[2], n;
    cin >> n;
    cin >> x[0] >> x[1]; // x0,y0
    double min1 = x[0], max1 = x[1], min2 = x[1], max2 = x[0];
    for (int i = 1; i < n; i++) {
        cin >> x[0] >> x[1];
        if (i % 2 == 1)
        // Zig:even=find min1-max1 ,odd=find max1-min1
        // Zag:          max1-min1           min1-max1
        {
            max1 = max(max1, x[0]);
            min1 = min(min1, x[1]);

            max2 = max(max2, x[1]);
            min2 = min(min2, x[0]);
        } else // even line
        {
            max1 = max(max1, x[1]);
            min1 = min(min1, x[0]);

            max2 = max(max2, x[0]);
            min2 = min(min2, x[1]);
        }
    }

    string zz;
    cin >> zz;
    if (zz == "Zig-Zag") {
        cout << min1 << " " << max1;
    } else {
        cout << min2 << " " << max2;
    }
}