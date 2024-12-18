#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    string a, aa, b;
    map<string, string> m;
    while (n--) {
        cin >> a >> aa >> b;
        a = a + " " + aa;
        m[a] = b;
        m[b] = a;
    }
    cin >> n;
    cin.ignore();
    while (n--) {
        string input;
        getline(cin, input);
        auto itr = m.find(input);
        if (itr != m.end()) {
            cout << input << " --> " << (*itr).second << endl;
            continue;
        } else {
            cout << input << " --> "
                 << "Not found" << endl;
        }
    }
}