#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<pair<string, string>> v;
    string a, b;
    while (cin >> a) {
        if (a == "q") break;
        cin >> b;
        v.push_back({a, b});
    }
    string id;
    vector<string> grade = {"F", "D", "D+", "C", "C+", "B", "B+", "A"};
    while (cin >> id) {
        for (auto itr : v) {
            if (id == itr.first) {
                for (int i = 0; i < grade.size() - 1; i++) {
                    if (itr.second == grade[i]) {
                        itr.second = grade[i + 1];
                        break;
                    }
                }
            }
        }
    } // END INPUT
    for (auto itr : v) {
        cout << itr.first << " " << itr.second << endl;
    }
}