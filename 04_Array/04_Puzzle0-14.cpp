#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int input[n][n], id = 0, ivs[n * n], zero;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> input[i][j];
            if (input[i][j] == 0) {
                zero = i;
            }
            ivs[id] = input[i][j];
            id++; // now we got int ivs[]={4,1,0,10,...}
        }
    }
    // inversion
    int count = 0; // array1D so index to n*n
    for (int i = 0; i < n * n - 1; i++) {
        for (int j = i + 1; j < n * n; j++) {
            if (ivs[i] > ivs[j] && ivs[i] != 0 && ivs[j] != 0) {
                count++;
            }
        }
    }
    // check
    if ((n % 2 == 1 && count % 2 == 0) || (n % 2 == 0 && ((zero % 2 == 1 && count % 2 == 0) || (zero % 2 == 0 && count % 2 == 1)))) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    // cout << count << " " << zero;
}