#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> v;
    int n;
    cin >> n;
    v.push_back(n);
    while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
        v.push_back(n);
    }
    auto k = v.size() >= 15 ? v.end() - 15 : v.begin();
    for (auto itr = k; itr < v.end(); itr++) {
        cout << *itr;
        if (itr != v.end() - 1) cout << "->";
    }
}