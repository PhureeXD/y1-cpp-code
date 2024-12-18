#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, n2;
    cin >> n;
    while (n--) {
        cin >> n2;
        long long a;
        cin >> a;
        long long min = a, sum = a;
        while (--n2) {
            cin >> a;
            sum += a;
            if (a < min) min = a;
        }
        cout << sum - min << endl;
    }
}