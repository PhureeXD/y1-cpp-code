#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int lift[n][3];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> lift[i][j];
        }
    }
    int m;
    cin >> m;
    int we[m][2];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> we[i][j];
        }
    }
    // Output //N,m for we & num,n for lift
    for (int N = 0; N < m; N++) {
        int len[n];
        for (int num = 0; num < n; num++) {
            bool up = true, stay = false;
            if (lift[num][1] > lift[num][2])
                up = false;
            else if (lift[num][1] == lift[num][2])
                stay = true;

            if (up && (we[N][0] <= we[N][1]) && (lift[num][1] <= we[N][0]) && (we[N][0] <= lift[num][2])) {
                len[num] = abs(we[N][1] - lift[num][2]);
            } else if (!(up) && (we[N][0] > we[N][1]) && (lift[num][1] >= we[N][0]) && (we[N][0] >= lift[num][2])) {
                len[num] = abs(we[N][1] - lift[num][2]);
            } else {
                len[num] = abs((we[N][0] - lift[num][2])) + abs((we[N][1] - we[N][0]));
            }
            // cout << len[num] << " ";
        }
        int min1 = len[0], minlift = lift[0][0];
        for (int i = 0; i < n; i++) {
            if (min1 > len[i]) {
                min1 = len[i];
                minlift = lift[i][0];
            }
        }
        cout << ">> " << minlift << endl;
    }
}