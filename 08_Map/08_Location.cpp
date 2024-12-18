#include <bits/stdc++.h>
using namespace std;
int main() {
    // {"id",{"A","S"}}
    int n;
    cin >> n;
    string id, ct;
    map<string, vector<string>> m;
    vector<string> m2, out;
    while (n--) {
        cin >> id;
        m2.push_back(id);
        while (cin >> ct) {
            if (ct == "*") break;
            m[id].push_back(ct);
        }
    }
    cin >> id;
    bool none = true;
    for (string same : m[id]) {
        for (auto itr : m) {
            for (auto itr2 = itr.second.begin(); itr2 != itr.second.end(); itr2++) {
                if (*itr2 == same) {
                    if (itr.first != id) {
                        out.push_back(itr.first);
                        none = false;
                    }
                    break;
                }
            }
        }
    }
    if (none) {
        cout << ">> Not Found";
    } else {
        for (string s : m2) {
            for (string ss : out) {
                if (s == ss) {
                    cout << ">> " << s << endl;
                    break;
                }
            }
        }
    }
}