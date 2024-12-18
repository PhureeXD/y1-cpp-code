#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string a;
    double N;
    map<string, double> m;
    m["THB"] = 1.0;
    cin >> n;
    while (n--) {
        cin >> a >> N;
        m[a] = N;
    }
    int num;
    cin >> num;
    vector<string> last;
    while (cin >> a) {
        last.push_back(a);
    }
    auto key = last.begin();
    cout << num << " " << *key;
    for (key = last.begin() + 1; key != last.end(); key++) {
        if (m.find(*key) != m.end()) {
            num = (m[*(key - 1)] * num / m[*key]);
        }
        cout << " -> " << num << " " << *key;
    }
}