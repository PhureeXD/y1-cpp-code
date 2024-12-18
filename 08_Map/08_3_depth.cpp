#include <bits/stdc++.h>
using namespace std;
int main() {
    map<string, int> m;
    int n;
    cin >> n;
    string a;
    double b;
    while (n--) {
        cin >> a >> b;
        m[a] = b;
    }
    cin >> n;
    string c, d, e, f;
    vector<pair<double, vector<string>>> m2;
    while (n--) {
        cin >> a >> b >> c >> d >> e >> f;
        m2.push_back({-b, {a, c, d, e, f}});
    } //? {-44.5,{id,subject,}}
    sort(m2.begin(), m2.end());

    vector<pair<string, string>> v; //? {{id,subject}}
    for (auto itr : m2) {
        for (auto itr2 = itr.second.begin() + 1; itr2 != itr.second.end(); itr2++) {
            if (m[*itr2] != 0) {
                v.push_back({*(itr.second.begin()), *itr2});
                m[*itr2]--;
                break; //! important from exceed
            }
        }
    }

    sort(v.begin(), v.end());
    for (auto itr : v) {
        cout << itr.first << " " << itr.second << endl;
    }
}