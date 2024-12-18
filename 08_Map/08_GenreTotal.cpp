#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, a2, b, c;
    map<string, int> m;
    while (cin >> a >> a2 >> b >> c) {
        int min, sec, pos = c.find(":");
        min = stoi(c.substr(0, pos));
        sec = stoi(c.substr(pos + 1));
        if (m.find(b) == m.end()) {
            m[b] = min * 60 + sec;
        } else {
            m[b] += min * 60 + sec;
        }
    }
    set<tuple<int, string>> tup;
    for (auto pair : m) {
        tup.insert({pair.second, pair.first});
    }
    int count = 0;
    for (auto key = tup.rbegin(); count != 3 && key != tup.rend(); key++) {
        count++;
        cout << get<1>(*key) << " --> " << get<0>(*key) / 60 << ":" << get<0>(*key) % 60 << endl;
    }
}