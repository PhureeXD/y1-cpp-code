#include <iostream>
#include <string>
using namespace std;
int main() {
    string r[10] = {"Robert", "William", "James", "John", "Margaret", "Edward", "Sarah", "Andrew", "Anthony", "Deborah"};
    string n[10] = {"Dick", "Bill", "Jim", "Jack", "Peggy", "Ed", "Sally", "Andy", "Tony", "Debbie"};
    int m;
    cin >> m;
    while (m--) {
        string in;
        bool notfound = 1;
        cin >> in;
        for (int i = 0; i < 10; i++) {
            if (in == r[i]) {
                cout << n[i] << endl;
                notfound = 0;
            } else if (in == n[i]) {
                cout << r[i] << endl;
                notfound = 0;
            }
        }
        if (notfound) {
            cout << "Not found" << endl;
        }
    }
}