#include <bits/stdc++.h>
using namespace std;
bool Warp(int now, int end, map<int, set<int>> &m) {
    if (now == end) return true; //{key,{a1,a2}}
    if (m.find(now) != m.end()) {
        auto j = m.find(now);
        for (auto i = (*j).second.begin(); i != (*j).second.end(); i++) {
            int next = *i;
            if (m.find(next) != m.end() || next == end) {
                if (Warp(next, end, m) == false) continue;
                return Warp(next, end, m);
            }
        }
    }
    return false;
}

int main() {
    int n, now, end;
    cin >> n >> now >> end;
    map<int, set<int>> m;
    int s, e;
    while (n--) {
        cin >> s >> e;
        m[s].insert(e);
    }
    if (Warp(now, end, m))
        cout << "yes";
    else
        cout << "no";
}