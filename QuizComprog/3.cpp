#include <bits/stdc++.h>
using namespace std;
void Print(int y_score, int z_score, vector<int> &detail, string team) {
    cout << ((y_score > z_score) ? "*" : "") << team << " " << y_score << " [ ";
    for (auto &i : detail)
        cout << i << " ";
    cout << "]" << endl;
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        vector<int> y1, z1;
        int y1s = 0, z1s = 0;
        string a, b, c;
        cin >> a >> b;
        while (cin >> c) {
            if (c == "*") break;
            int pos = c.find('-');
            int y = stoi(c.substr(0, pos)), z = stoi(c.substr(pos + 1));
            y1.push_back(y);
            z1.push_back(z);
            if (y > z) {
                ++y1s;
            } else
                ++z1s;
        }
        Print(y1s, z1s, y1, a);
        Print(z1s, y1s, z1, b);
    }
}