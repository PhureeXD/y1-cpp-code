#include <bits/stdc++.h>
using namespace std;
int main() {
    map<string, vector<string>> m;
    int n, n2;
    string a, b;
    cin >> n >> n2;
    while (n--) {
        cin >> a >> b;
        m[b].push_back(a);
    }
    while (n2--) {
        cin >> n >> a >> b;
        if (n == 1) {
            for (auto &i : m) {
                for (auto j = i.second.begin(); j != i.second.end(); j++) {
                    if (*j == a) {
                        i.second.erase(j);
                        break;
                    }
                }
            }
            m[b].push_back(a);
        } else if (n == 2) {
            for (auto &i : m[a]) {
                m[b].push_back(i);
            }
            m.erase(a);
        }
    }
    for (auto &i : m) {
        sort(i.second.begin(), i.second.end());
        cout << i.first << ": ";
        for (auto &j : i.second) {
            cout << j << " ";
        }
        cout << endl;
    }
}