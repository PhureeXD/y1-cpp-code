#include <bits/stdc++.h>
using namespace std;
int main() {
    map<string, set<string>> m;
    string s, s2;
    while (cin >> s) {
        if (cin >> s2) {
            m[s].insert(s2);
            m[s2].insert(s);
        }
    } //! {siam,{chitlom,nation}}
    auto itr = m.find(s);
    if (itr == m.end()) {
        cout << s;
        return 0;
    }
    set<string> ans;
    for (string S : ((*itr).second)) {
        ans.insert(S);
        auto itr2 = m.find(S);
        for (string SS : ((*itr2).second)) {
            ans.insert(SS);
        }
    }
    for (string S : ans) {
        cout << S << endl;
    }
}