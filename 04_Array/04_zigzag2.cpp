#include <bits/stdc++.h>
using namespace std;
int maxx(int d[], int n) {
    int mx = d[0];
    for (int i = 0; i < n; i++) {
        if (d[i] > mx) mx = d[i];
    }
    return mx;
}
int minn(int d[], int n) {
    int mn = d[0];
    for (int i = 1; i < n; i++) {
        if (d[i] < mn) mn = d[i];
    }
    return mn;
}
int main() {
    int n;
    cin >> n;
    int red[n], blue[n];
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            cin >> red[i] >> blue[i];
        else
            cin >> blue[i] >> red[i];
    }
    string last;
    cin >> last;
    if (last == "Zig-Zag")
        cout << minn(red, n) << ' ' << maxx(blue, n);
    else // Zag-Zig
        cout << minn(blue, n) << ' ' << maxx(red, n);
}