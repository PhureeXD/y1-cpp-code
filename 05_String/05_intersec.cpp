#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int intersec(int sq1[], int sq2[]) {
    // width=min(ขอวขวา)-max(ขอบซ้าย) X-axis 2,0
    int w = min(sq1[2], sq2[2]) - max(sq1[0], sq2[0]);
    // height=min(ขอบบน)-max(ขอบล่าง) Y-axis 3,1
    int h = min(sq1[3], sq2[3]) - max(sq1[1], sq2[1]);
    if (w < 0 || h < 0) return 0;
    return w * h;
}
int main() {
    int n;
    cin >> n;
    int sq[n][4];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++)
            cin >> sq[i][j];
    }
    int maxx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int same_area = intersec(sq[i], sq[j]);
            if (same_area > maxx) maxx = same_area;
        }
    }
    if (maxx != 0) {
        cout << "Max overlapping area = " << maxx << endl;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int same_area = intersec(sq[i], sq[j]);
                if (same_area == maxx)
                    cout << "rectangles " << i << " and " << j << endl;
            }
        }
    } else {
        cout << "No overlaps";
    }
}