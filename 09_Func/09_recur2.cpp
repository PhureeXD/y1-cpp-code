#include <iostream>
#include <map>
using namespace std;
int F(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n % 2 == 0) {
        return (2 * F((n / 2) - 1) + F(n / 2)) * F(n / 2);
    } else {
        return F((n + 1) / 2) * F((n + 1) / 2) + F(((n + 1) / 2) - 1) * F(((n + 1) / 2) - 1);
    }
}
int M(int n) { // Motzkin number
    if (n == 0 || n == 1) return 1;
    int sum = 0;
    for (int k = 0; k <= n - 2; k++) {
        sum += M(k) * M(n - 2 - k);
    }
    return M(n - 1) + sum;
}
int S(int n) { // Schröder–Hipparchus Number
    if (n == 1 || n == 2) return 1;
    return ((6 * n - 9) * S(n - 1) - (n - 3) * S(n - 2)) / n;
}
int D(int n) { // Derangement
    if (n == 0) return 1;
    int one = -1;
    if (n % 2 == 0) one = 1;
    return n * D(n - 1) + one;
}
int main() {
    map<string, int (*)(int)> func = {{"F", F}, {"M", M}, {"S", S}, {"D", D}};
    string fn;
    int p;
    while (cin >> fn >> p) {
        if (func.find(fn) != func.end())
            cout << fn << '(' << p << ") = " << func[fn](p) << endl;
    }
    return 0;
}