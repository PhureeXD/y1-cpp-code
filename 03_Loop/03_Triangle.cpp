#include <iostream>
using namespace std;
int main() {
    int h;
    cin >> h;
    cout << string(h - 1, '.') << "*" << endl; // first
    int b = h - 2, c = 1;
    for (int i = 1; i < h - 1; i++) {
        // ระหว่างทาง i ใช้เพื่อแค่วนลูป all-2รอบ
        cout << string(b, '.') << '*' << string(c, '.') << '*' << endl;
        b--, c += 2;
    }
    cout << string(2 * h - 1, '*') << endl; // last
}