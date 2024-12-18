#include <cmath>
#include <iostream>
#include <string>
using namespace std;
int main() {
    string a, aa;
    int b, same = 1;
    cin >> a;
    cin >> b;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == a[i + 1]) {
            same += 1;
            if (same >= b) {
                if (a[i + 1] == a[i + 2]) {
                    continue;
                    // prevent eg. aaa "2" -> a
                }

                for (int j = 0; j < same; j++) {
                    a[i + 1 - j] = ' ';
                }
            }
        } else {
            same = 1;
        }
    }
    cout << a << endl;
    for (auto c : a) {
        if (c != ' ') {
            aa += c;
        }
    }

    cout << aa;
}