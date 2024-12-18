#include <cmath>
#include <iostream>
using namespace std;

long long all(long long n) {
    long long sum = 1;
    int k = 1;
    for (; pow(10, k) <= n; k++) {
        sum += 9 * (long long)pow(10, k - 1) * k; // 0 till before last
    }
    sum += k * (n - (long long)pow(10, k - 1) + 1); // last 1*(20-1+1)
    // cout << k << endl;
    return sum;
}
int main() {
    long long n, m;
    cin >> m >> n;

    cout << all(n) - all(m - 1) << endl;
}
