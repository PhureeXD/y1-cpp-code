#include <cmath>
#include <iostream>
using namespace std;

int main() {
    long minn = 9999, maxx = -9999, min1 = 9999, max1 = -9999;
    int count = 0;
    long x[80], y[80];
    // bool state;
    while (true) {
        long a, b;
        cin >> a;

        if (a != -998 && a != -999) {
            cin >> b;
            x[count] = a; // diff loop diff a,b
            y[count] = b;
            count++;
        } else if (a == -998) {
            y[count + 1] = -9999;
            x[count + 1] = -9999;
            for (int i = 0; i < count; i += 2) {
                minn = min(x[i], y[i + 1]);
                min1 = min(min1, minn);
                maxx = max(y[i], x[i + 1]);
                max1 = max(max1, maxx); // y0x1y2x3
            }
            break;
        } else // if (a == -999)
        {
            y[count + 1] = 9999;
            x[count + 1] = 9999;
            for (int i = 0; i < count; i += 2) {
                minn = min(y[i], x[i + 1]);
                min1 = min(minn, min1);
                maxx = max(x[i], y[i + 1]);
                max1 = max(maxx, max1);
            }
            break;
        }
    }
    cout << min1 << " " << max1;
}