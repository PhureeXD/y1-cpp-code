#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> v;
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    v.push_back(n);
    while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
        v.push_back(n);
    }
    if (v.size() >= 15) {
        for (auto itr = v.end() - 15; itr < v.end(); itr++) {
            if (itr == v.end() - 1) {
                cout << *itr;
            } else {
                cout << *itr << "->";
            }
        }
    } else {
        for (auto itr = v.begin(); itr < v.end(); itr++) {
            if (itr == v.end() - 1) {
                cout << *itr;
            } else {
                cout << *itr << "->";
            }
        }
    }
}