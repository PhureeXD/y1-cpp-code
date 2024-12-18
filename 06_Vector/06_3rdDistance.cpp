#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    double x, y;
    vector<tuple<double, int, double, double>> v;
    int index = 1;
    while (cin >> x >> y) {
        double dis = sqrt(pow(x, 2) + pow(y, 2));
        v.push_back({dis, index, x, y});
        index++;
    }
    sort(v.begin(), v.end());
    auto itr = v.begin();
    itr += 2;
    cout << "#" << get<1>(*itr) << ": "
         << "(" << get<2>(*itr) << ", " << get<3>(*itr) << ")";
}