#include <cmath>
#include <iostream>
#include <string>
using namespace std;
int main() {
    string base, up;
    int eachloop[10] = {1, 1, 4, 4, 2, 1, 1, 4, 4, 2};
    while (cin >> base >> up) {
        if (up == "0") {
            cout << ">> 1" << endl;
        } else {
            int base1 = base[base.length() - 1] - '0';
            // base1=last,up1=last two
            int up1 = stoi(("0" + up).substr(up.length() - 1));
            int up1_common = up1 % eachloop[base1];
            if (up1_common == 0)
                up1_common = 4;
            int smallval = (int)pow(base1, up1_common) % 10;
            cout << ">> " << smallval << endl;
        }
    }
}