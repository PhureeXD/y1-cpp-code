#include <bits/stdc++.h>
using namespace std;
// int main() {
//     int R, C;
//     cin >> R >> C;
//     double in[R][C];
//     for (int i = 0; i < R; i++) {
//         for (int j = 0; j < C; j++) {
//             cin >> in[i][j];
//         }
//     }
//     // Center pos only
//     for (int i = 1; i < R - 1; i++) {
//         for (int j = 1; j < C - 1; j++) {
//             double re_sum = 0;
//             // 3*3 summation from center pos
//             for (int R = -1; R < 2; R++) {
//                 for (int C = -1; C < 2; C++) {
//                     re_sum += in[i + R][j + C];
//                 }
//             }
//             cout << round(re_sum / 9 * 100) / 100 << " ";
//         }
//         // after a Row with ALL columns then endline
//         cout << endl;
//     }
// }

int main() {
    int R, C;
    cin >> R >> C;
    double input[R][C];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> input[i][j];
        }
    }
    //
    for (int i = 1; i < R - 1; i++) {
        for (int j = 1; j < C - 1; j++) {
            double sum = 0;
            for (int a = -1; a <= 1; a++) {
                for (int b = -1; b <= 1; b++) {
                    sum += input[i + a][j + b];
                }
            }
            cout << round(sum / 9 * 100) / 100 << " ";
        }
        cout << endl;
    }
}