/*Method1
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    double input[n];
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    double ans;
    for (int j = 0; j < n; j++) {
        for (int i = j; i >= 0; i--) // 0:0 /1:1 0 /2:2 1 0
        {
            if (i == j) {
                ans = input[i];
            } else {
                ans = input[i] + 1 / ans;
            }
        }
        cout << setprecision(10) << ans << endl;
    }
}*/

#include <iomanip>
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    double input[n];
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    for (int i = 0; i < n; i++) {
        double ans = input[i];
        for (int j = i - 1; j >= 0; j--) {
            ans = 1 / ans + input[j]; // if i=0 it will not go in in this loop
        }
        cout << setprecision(10) << ans << endl;
    }
}
