#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int pc[n];
    for (int i = 0; i < n; i++) {
        cin >> pc[i];
    }
    for (int sq = 0; sq < n; sq++) {
        cout << pc[sq] << " ";
    }
    cout << endl; // Now Loop -1

    for (int i = 0; i < n - 1; i++) {
        int max = 0, int_max = 0, temp = 0;
        // max pos
        for (int sq = 0; sq < n - i; sq++) {
            if (pc[sq] > int_max) {
                max = sq;
                int_max = pc[sq];
            }
        }
        // max == right:do nothing =  just continue the loop
        // max neither right nor left (normal case)
        // n-1=last pos of length n
        if (max != n - 1 - i && max != 0) {
            // reverse max to left [0,max]
            for (int sq = 0; sq < (max + 1) / 2; sq++) {
                temp = pc[sq];
                pc[sq] = pc[max - sq];
                pc[max - sq] = temp;
            }
            for (int sq = 0; sq < n; sq++) {
                cout << pc[sq] << " ";
            }
            cout << endl;
            cout << "Lmax" << endl;
        }
        // after max in left side but stil, if max in right = do nothing
        if (max != n - 1 - i) {
            // reverse max,max-,max-- from n to n-i
            for (int sq = 0; sq < ((n - 1 - i) + 1) / 2; sq++) {
                temp = pc[sq];
                pc[sq] = pc[(n - 1 - i) - sq];
                pc[(n - 1 - i) - sq] = temp;
            }
            for (int sq = 0; sq < n; sq++) {
                cout << pc[sq] << " ";
            }
            cout << endl;
            cout << "max--" << endl;
        }
    }
}