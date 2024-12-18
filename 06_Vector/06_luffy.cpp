#include <bits/stdc++.h>
using namespace std;
int main() {
    string a;
    cin >> a;
    a = a + "$";
    vector<string> v;
    for (int i = 0; i < a.length(); i++) {
        string part = a.substr(i, a.length());
        if (i > 0) part += a.substr(0, i);
        v.push_back(part);
    }
    sort(v.begin(), v.end());
    for (string line : v) {
        cout << line[a.length() - 1];
    }
}