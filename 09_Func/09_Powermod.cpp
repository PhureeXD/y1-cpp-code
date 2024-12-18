#include <cmath>
#include <iostream>
using namespace std;
int mod(int a, int k, int m) {
    if (k == 0) {
        return 1;
    } else if (k % 2 == 0) {
        return (mod(a, k / 2, m) * mod(a, k / 2, m)) % m;
    } else {
        return a * (mod(a, k / 2, m) * mod(a, k / 2, m)) % m;
    }
}
int main() {
    int a, k, m;
    cin >> a >> k >> m;
    cout << mod(a, k, m);
}