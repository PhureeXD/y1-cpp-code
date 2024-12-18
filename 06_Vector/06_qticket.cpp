#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<double> t;
    vector<pair<int, double>> v;
    string cmd;
    int ticket, count = -1;
    double num;
    while (n--) {
        cin >> cmd;
        if (cmd == "reset") {
            cin >> ticket;
        } else if (cmd == "new") {
            cin >> num;
            v.push_back({ticket, num});
            cout << ">> ticket " << ticket << endl;
            ticket++;
        } else if (cmd == "next") {
            ++count;
            cout << ">> call " << get<0>(v[0]) + count << endl;
        } else if (cmd == "order") {
            cin >> num;
            cout << ">> qtime " << get<0>(v[0]) + count << " " << num - get<1>(v[count]) << endl;
            t.push_back(num - get<1>(v[count]));
        } else {
            double time = 0;
            for (auto i : t)
                time += i;
            time = time / t.size();
            cout << ">> avg_qtime " << round(time * 100.0) / 100.0 << endl;
        }
    }
}