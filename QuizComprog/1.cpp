#include <bits/stdc++.h>
using namespace std;
int main() {
    map<string, int> m;
    set<int> out;
    int n, a;
    cin >> n;
    string s;
    while (n--) {
        cin >> s >> a;
        a *= -1;
        if (m[s] > a || m.find(s) == m.end()) m[s] = a;
    }
    cin >> n;
    for (auto &i : m)
        out.insert(i.second);
    int index = 0;
    for (auto i = out.begin(); i != out.end(); i++) {
        cout << -*i << " ";
        ++index;
        for (auto &j : m)
            if (*i == j.second) cout << j.first << " ";
        cout << endl;
        if (index == n) break;
    }
}