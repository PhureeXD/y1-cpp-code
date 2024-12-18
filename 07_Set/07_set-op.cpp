#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<set<int>> s; //? {{line1},{line2}}
    string line;
    while (getline(cin, line)) { // 12 25
        set<int> temp;
        string part;
        line += " ";
        for (char c : line) {
            if (c == ' ') {          // FOUND mean push part to v
                if (!part.empty()) { // prevent line have deli next to each other eg.(helloo....lo) (. have more than 1)
                    temp.insert(stoi(part));
                    part = "";
                }
            } else // NOT FOUND mean collect part
                part += c;
        }
        s.push_back(temp);
    }

    set<int> u = s[0], i = s[0], d = s[0]; //* first data cant compare
    for (int j = 1; j < s.size(); j++) {
        //! union
        u.insert(s[j].begin(), s[j].end());
        //! intersec // i=have && s[i]=have -> new i
        set<int> temp;
        for (int a : i)
            if (s[j].find(a) != s[j].end()) temp.insert(a);
        i = temp;
        //! difference
        temp.clear();
        for (int a : d) //* have in d but dont have in s[j] so loop d then check s[j]
            if (s[j].find(a) == s[j].end()) temp.insert(a);
        d = temp;
    }

    cout << "U:";
    if (u.empty()) cout << " empty set";
    for (int a : u)
        cout << ' ' << a;
    cout << endl;
    cout << "I:";
    if (i.empty()) cout << " empty set";
    for (int a : i)
        cout << ' ' << a;
    cout << endl;
    cout << "D:";
    if (d.empty()) cout << " empty set";
    for (int a : d)
        cout << ' ' << a;
}
