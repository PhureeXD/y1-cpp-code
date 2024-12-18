#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, same = 1, same2 = 1;
    vector<int> v;
    while (cin >> n)
        v.push_back(n);
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == v[i + 1] && i != v.size() - 1)
            same++;
        else {
            if (same > same2) same2 = same;
            same = 1;
        }
    }
    vector<tuple<int, int, int>> v2;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == v[i + 1] && i != v.size() - 1)
            same++;
        else {
            if (same == same2) v2.push_back({v[i], i - same2 + 1, i + 1});
            same = 1;
        }
    }
    sort(v2.begin(), v2.end());
    for (auto t : v2) {
        cout << get<0>(t) << " --> x[ " << get<1>(t) << " : " << get<2>(t) << " ]" << endl;
    }
    cout << "Max length: " << same2;
}