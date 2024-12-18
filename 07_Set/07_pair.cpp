#include <bits/stdc++.h>
using namespace std;
int main() {
    set<int> s;
    int K, num, count = 0;
    bool half = false;
    cin >> K;
    while (cin >> num) {
        if (num > K) continue;
        s.insert(num);
        if (s.find(K - num) != s.end()) count++;
        if (num == K / 2 && K % 2 == 0) half = true;
    }
    if (half)
        cout << count - 1;
    else
        cout << count;
}