#include <bits/stdc++.h>
using namespace std;
int main() {
    map<string, string> m, m2;
    int N;
    cin >> N;
    while (N--) {
        string name, nick;
        cin >> name >> nick;
        m[name] = nick;
        m2[nick] = name; // todo key:nick->value:name
    }
    cin >> N;
    while (N--) {
        string input;
        cin >> input;
        auto itr = m.find(input);
        if (itr != m.end()) {
            cout << (*itr).second << endl;
            continue;
        }
        itr = m2.find(input);
        if (itr != m2.end()) {
            cout << (*itr).second << endl;
            continue;
        }
        cout << "Not found" << endl;
    }
}