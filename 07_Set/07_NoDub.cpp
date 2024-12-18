#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, count = 0;
    bool found = false;
    set<int> s;
    while (cin >> a) {
        ++count;
        if (s.find(a) == s.end())
            s.insert(a);
        else {
            found = true;
            break;
        }
    }
    if (found)
        cout << count;
    else
        cout << -1;
}