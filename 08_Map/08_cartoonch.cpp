#include <bits/stdc++.h>
using namespace std;
int main() {
    map<string, vector<string>> m;
    vector<string> sq;
    string name, type;
    while (cin >> name >> type) {
        m[type].push_back(name);
        if ((find(sq.begin(), sq.end(), type) == sq.end()))
            sq.push_back(type);
    }
    for (auto key : sq) {
        cout << key << ": ";
        for (auto ii : m[key]) {
            cout << ii << " ";
        }
        cout << endl;
    }
}