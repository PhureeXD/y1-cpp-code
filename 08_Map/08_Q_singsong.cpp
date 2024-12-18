#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    cin.ignore();
    string line;
    map<string, vector<string>> m; //! {{Song},{Name,Name2}}
    while (n--) {
        getline(cin, line);
        int com = line.find(",", 0);
        m[line.substr(0, com)].push_back(line.substr(com + 2));
    }
    getline(cin, line);
    int com = line.find(",", 0), begin = 0;
    string s;
    bool loop = true;
    while (loop) {
        if (com != string::npos)
            s = line.substr(begin, com - begin);
        else { //! 1. after last comma it will have last name (a,b,c) the c one 2. if we input 1 name (a)
            s = line.substr(begin);
            loop = false;
        }
        cout << s << " -> ";
        if (m.find(s) != m.end()) {
            for (int index = 0; index < m[s].size(); index++) {
                if (index != m[s].size() - 1) {
                    cout << m[s][index] << ", ";
                } else {
                    cout << m[s][index] << endl;
                }
            }
        } else {
            cout << "Not found" << endl;
        }
        begin = com + 2;
        com = line.find(",", com + 1);
    }
}
