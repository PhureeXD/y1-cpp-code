#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<tuple<double, string>> list; //{price,code}
    string first;
    double second;
    while (cin >> first) {
        if (first != "END") {
            cin >> second; //{price,code}
            list.push_back({second, first});
        } else
            break;
    }
    string last;
    vector<tuple<double, string>> list2;
    while (cin >> last) {
        for (auto itr = list.begin(); itr < list.end(); itr++) {
            if (last == get<1>(*itr)) { // check is the name in the list?
                bool have = false;
                for (auto itr2 = list2.begin(); itr2 < list2.end(); itr2++) {
                    if (last == get<1>(*itr2)) {
                        // check if it is in list2 if so we will just increase in that list2 or else create new list2
                        get<0>(*itr2) -= get<0>(*itr); // list2={-price,code}
                        have = true;
                    }
                }
                if (!have) // create new output after known that in list2 there still none of this codename
                    list2.push_back({-get<0>(*itr), get<1>(*itr)});
            }
        }
    }

    sort(list2.begin(), list2.end());
    if (!(list2.empty())) {
        for (auto itr = list2.begin(); itr < list2.begin() + 3; itr++) {
            cout << get<1>(*itr) << " " << -get<0>(*itr) << endl;
        }
    } else {
        cout << "No Sales";
    }
}