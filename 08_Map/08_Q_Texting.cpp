#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, out;
    map<string, string> t2k = {{" ", "0"}, {"a", "2"}, {"b", "22"}, {"c", "222"}, {"d", "3"}, {"e", "33"}, {"f", "333"}, {"g", "4"}, {"h", "44"}, {"i", "444"}, {"j", "5"}, {"k", "55"}, {"l", "555"}, {"m", "6"}, {"n", "66"}, {"o", "666"}, {"p", "7"}, {"q", "77"}, {"r", "777"}, {"s", "7777"}, {"t", "8"}, {"u", "88"}, {"v", "888"}, {"w", "9"}, {"x", "99"}, {"y", "999"}, {"z", "9999"}};
    map<string, string> k2t;
    for (auto c : t2k) {
        k2t[c.second] = c.first;
    }
    vector<string> v;
    while (getline(cin, a)) {
        if (a.substr(0, 3) == "T2K") {
            a = a.substr(4);
            for (int i = 0; i < a.length(); i++) {
                a[i] = tolower(a[i]);
                string z = a.substr(i, 1);
                out += t2k[z] + " ";
            }
            cout << ">> " << out << endl;
        } else {
            a = a.substr(4);
            int space = a.find(" ", 0), begin = 0;
            while (space != string::npos) {
                // cout << begin << " " << space << endl;
                string z = a.substr(begin, space - begin);
                out += k2t[z];
                begin = space + 1;
                space = a.find(" ", space + 1);
            }
            out += k2t[a.substr(begin)];
            cout << ">> " << out << endl;
        }
        out = "";
    }
}