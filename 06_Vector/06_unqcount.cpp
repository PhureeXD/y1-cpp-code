#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    vector<int> v, v2;
    while (cin >> n) {
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    int diff = 0;
    for (auto itr = v.begin(); itr < v.end(); itr++) {
        if (*itr != *(itr + 1)) {
            diff++;
            v2.push_back(*itr);
        }
    }
    cout << diff << endl;
    if (v2.size() > 10) {
        for (auto itr = v2.begin(); itr < v2.begin() + 10; itr++) {
            cout << *itr << " ";
        }
    } else {
        for (auto itr = v2.begin(); itr < v2.end(); itr++) {
            cout << *itr << " ";
        }
    }
}