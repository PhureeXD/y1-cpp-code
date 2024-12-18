#include <iostream>
#include <map>
using namespace std;
int H(int n) { // Tower of Hanoi
    if (n >= 1) {
        return 2 * H(n - 1) + 1;
    }
    return 0;
}
int C(int n) { // Catalan Number
    if (n == 0)
        return 1;
    int sum = 0;
    if (n >= 0) {
        for (int k = 0; k < n; k++) {
            sum += C(k) * C(n - k - 1);
        }
    }
    return sum;
}
int M(int n);
int F(int n) { // Female sequence
    if (n > 0) return n - M(F(n - 1));
    return 1;
}
int M(int n) { // Male sequence
    if (n > 0) return n - F(M(n - 1));
    return 0;
}
int main() {
    map<string, int (*)(int)> func = {{"H", H}, {"C", C}, {"F", F}, {"M", M}};
    string fn;
    int p;
    while (cin >> fn >> p) {
        if (func.find(fn) != func.end())
            cout << fn << '(' << p << ") = " << func[fn](p) << endl;
    }
    return 0;
}