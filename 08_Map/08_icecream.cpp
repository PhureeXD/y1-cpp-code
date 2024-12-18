#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    map<string, double> m;
    string a;
    double b;
    while (n--) {
        cin >> a >> b;
        m[a] = b;
    }
    cin >> n;
    double sum = 0;
    map<string, double> m2;
    while (n--) {
        cin >> a >> b;
        if (m.find(a) != m.end()) {
            m2[a] += b * m[a];
            sum += b * m[a];
        }
    }
    vector<pair<double, string>> v;
    for (auto i : m2) {
        v.push_back({-i.second, i.first});
    }
    sort(v.begin(), v.end());
    if (m2.empty())
        cout << "No ice cream sales";
    else {
        cout << "Total ice cream sales: " << sum << endl;
        cout << "Top sales: ";
        for (auto itr = v.begin();; itr++) {
            cout << (*itr).second << " ";
            if ((*itr).first != ((*(itr + 1)).first)) return 0;
        }
    }
}
