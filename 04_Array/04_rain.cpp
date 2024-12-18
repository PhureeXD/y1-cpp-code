#include <iostream>
#include <string>
using namespace std;
int main() {
    int n, sum = 0;
    cin >> n;
    int input[n];
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    for (int pos = 1; pos < n - 1; pos++) {
        int Lmax = input[0], Rmax = input[pos + 1];
        for (int i = 0; i < pos; i++) {
            if (input[i] > Lmax) {
                Lmax = input[i];
            } // LEFT
        }     // RIGHT
        for (int i = pos + 1; i < n; i++) {
            if (input[i] > Rmax) {
                Rmax = input[i];
            }
        }
        int grey;
        Rmax > Lmax ? grey = Lmax : grey = Rmax;
        if (input[pos] < grey) {
            sum += grey - input[pos];
        }
    }
    cout << sum;
}