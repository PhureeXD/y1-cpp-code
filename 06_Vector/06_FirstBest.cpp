#include <bits/stdc++.h>
using namespace std;

int main() {
    string cmd;
    cin >> cmd;
    vector<int> v;
    vector<tuple<int, int, vector<int>>> t; //{sum,size,out} (-1, normal_sort)
    int n;
    while (cin >> n) {
        v.push_back(n);
    }
    if (cmd == "first") {
        for (auto &i : v) {
            bool add = false;
            for (auto &j : t) {
                if (get<0>(j) + i <= 100) {
                    get<0>(j) += i;
                    get<1>(j)++;
                    get<2>(j).push_back(i);
                    add = true;
                    break;
                }
            }
            if (!add) t.push_back({i, 1, {i}});
        }
    } else if (cmd == "best") {
        for (auto &i : v) {
            bool add = false;
            int pos, index = 0, MIN = 9999;
            for (auto j : t) {
                int this_min = 100 - get<0>(j); // 100-99 < 100-98
                if (get<0>(j) + i <= 100 && this_min < MIN) {
                    pos = index;
                    MIN = this_min;
                    add = true;
                }
                index++;
            }
            // GOT MOST CLOSEST
            if (add) {
                get<0>(t[pos]) += i;
                get<1>(t[pos])++;
                get<2>(t[pos]).push_back(i);
            } else
                t.push_back({i, 1, {i}});
        }
    }

    for (auto &i : t) {
        get<0>(i) *= -1;
        sort(get<2>(i).begin(), get<2>(i).end());
    }
    sort(t.begin(), t.end());
    for (auto &i : t) {
        for (auto &j : get<2>(i)) {
            cout << j << " ";
        }
        cout << endl;
    }
}