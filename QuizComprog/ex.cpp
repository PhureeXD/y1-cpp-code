#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<tuple<long long, string>> v;
    set<string> out;
    long long n, m;
    string a;
    cin >> n;
    while (n--) {
        bool have = false;
        cin >> a >> m;
        for (auto &i : v) {
            if (get<1>(i) == a) {
                if (-get<0>(i) < -m) {
                    get<0>(i) = -m;
                    have = true;
                }
            }
        }
        if (!have) v.push_back({-m, a});
    }
    sort(v.begin(), v.end());
    cin >> n;
    long long index = 0;
    long long temp = 9999;
    for (auto &i : v) {
        set<string> sad;
        if (get<0>(i) == temp) continue;
        ++index;
        for (auto &j : v) {
            if (get<0>(i) == get<0>(j)) {
                if (out.find(get<1>(j)) != out.end()) continue;
                sad.insert(get<1>(j));
                out.insert(get<1>(j));
            }
        }
        if (sad.size() == 0) return 0;
        cout << -get<0>(i) << " ";
        for (auto s : sad)
            cout << s << ' ';
        cout << endl;
        if (index == n) break;
        temp = get<0>(i);
    }
}
