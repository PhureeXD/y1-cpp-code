#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<tuple<double, string, string>> v;
    string a, b;
    double s = 0;
    while (cin >> a) {
        if (a == "END") break;
        cin >> b;
        v.push_back({0, b, a}); //{0,score,name}
        s += stoi(b);
    }
    s /= 100;
    int hun = 0;
    for (auto &i : v) {
        double score = stoi(get<1>(i)) / s;
        get<0>(i) = -score;
        hun += (int)score;
    } // {-15.1,score,name}
    sort(v.begin(), v.end());
    auto v2(v);
    for (auto &i : v2) {
        int aa = (int)get<0>(i);
        get<0>(i) -= aa; // only decimal
    }
    sort(v2.begin(), v2.end());
    int want = 100 - hun;
    for (auto i = v2.begin(); i < v2.begin() + want; i++) {
        for (auto &j : v) {
            if (get<2>(*i) == get<2>(j)) {
                get<0>(j) -= 1; // cuz we let score(-) cuz we sort from max to min so we - to add
            }
        }
    }
    for (auto &i : v) {
        if (-get<0>(i) >= 1)
            cout << get<2>(i) << " " << -(int)get<0>(i) << " " << get<1>(i) << endl;
    }
}