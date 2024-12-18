#include <bits/stdc++.h>
using namespace std;
int main() {
    string grade;
    int n;
    cin >> n;
    double kit[n], low = 0, sum = 0;
    map<string, double> m = {{"A", 4}, {"B+", 3.5}, {"B", 3}, {"C+", 2.5}, {"C", 2}, {"D+", 1.5}, {"D", 1}, {"F", 0}};
    for (int i = 0; i < n; i++) {
        cin >> grade >> kit[i];
        sum += m[grade] * kit[i];
        low += kit[i];
    }
    sum /= low;
    cout << round(sum * 100) / 100;
}