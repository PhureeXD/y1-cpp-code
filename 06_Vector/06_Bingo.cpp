#include <bits/stdc++.h>
using namespace std;
void print(vector<string> v, string star) {
    string print1;
    for (auto s : v) {
        if (s != star)
            print1 += s + ", ";
    }
    cout << print1.substr(0, print1.length() - 2) << endl;
}
bool check(vector<string> v, vector<string> v2) {
    for (auto a : v) {
        if (find(v2.begin(), v2.end(), a) == v2.end()) return false;
    }
    return true;
}
int main() {
    vector<vector<string>> table; //{{},{},{},{}}
    char charr[6];
    for (int i = 0; i < 5; i++)
        cin >> charr[i];
    //! each full-name & got horizontal
    for (int i = 0; i < 5; i++) {
        vector<string> v(5);
        for (int ii = 0; ii < 5; ii++) {
            cin >> v[ii];
            v[ii] = charr[ii] + v[ii];
        }
        table.push_back(v);
    }
    //! vertical
    for (int j = 0; j < 5; j++) {
        vector<string> v;
        for (int i = 0; i < 5; i++) {
            v.push_back(table[i][j]);
        }
        table.push_back(v);
    }
    //! diagonal
    vector<string> v, vv;
    for (int i = 0; i < 5; i++)
        v.push_back(table[i][i]);
    table.push_back(v);
    //! diagonal2
    for (int i = 0; i < 5; i++)
        vv.push_back(table[4 - i][i]);
    table.push_back(vv);

    vector<string> draw = {table[2][2]}; //! free:name*
    string a;
    int count = 0;
    bool firstprint = true;
    while (cin >> a) {
        count += 1;
        draw.push_back(a);
        for (auto i : table) {
            if (check(i, draw)) {
                if (firstprint)
                    cout << count << endl;
                print(i, table[2][2]);
                firstprint = false; //! print firstprint so set it to false
            }
        }
        //? firstprint false  = already win
        if (not firstprint) return 0;
    }
}