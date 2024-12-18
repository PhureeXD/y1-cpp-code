#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b;
    set<string> s, lose;
    while (cin >> a >> b) {
        s.insert(a);
        lose.insert(b);
        if (lose.find(a) != lose.end()) s.erase(a);
        if (lose.find(b) != lose.end()) s.erase(b);
    }
    if (!s.empty()) {
        for (string ss : s) {
            cout << ss << " ";
        }
    } else
        cout << "None";
}