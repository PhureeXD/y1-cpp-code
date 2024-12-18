#include <iostream>
#include <string>
using namespace std;

int main() {
    string x, y;
    getline(cin, x);
    getline(cin, y);
    string x1 = x, y1 = y;

    int max_same = 0, pos_x = 0;
    for (int i = 0; i < y.length(); i++) {
        int same = 0;
        for (int p = 0; p < x.length(); p++) {
            if (x[p] == y[i + p]) { // think like we stick x and the one that was moved is y
                same++;
            }
        }
        if (same > max_same) {
            max_same = same;
            pos_x = i;
        }
    }

    int max_sameY = 0, pos_y = 0;
    for (int i = 0; i < x.length(); i++) {
        int same = 0;
        for (int p = 0; p < y.length(); p++) {
            if (y[p] == x[i + p]) {
                same++;
            }
        }
        if (same > max_sameY) {
            max_sameY = same;
            pos_y = i;
        }
    }

    bool slidex = true;
    if (max_same < max_sameY) {
        slidex = false;
    }

    if (slidex) {
        x1 = string(pos_x, '-') + x1;
        cout << x1 << endl;
        cout << y1 << endl;
        cout << max_same;
    } else {
        y1 = string(pos_y, '-') + y1;
        cout << x1 << endl;
        cout << y1 << endl;
        cout << max_sameY;
    }
}

/* Method 2:
#include <iostream>
#include <string>
using namespace std;
// this is same value focus on X (first input)
int same_value(string X, int pos_x, string Y, int pos_y) {
    int same = 0;
    while (pos_x < X.length() && pos_y <= Y.length()) {
        if (X[pos_x++] == Y[pos_y++]) {
            same++;
        }
    }
    return same;
}
// slide the second so focus on y moving
int findpos_maxsame(string x, string y) {
    int maxx = 0, pos_y_max = 0;
    for (int pos_y = 0; pos_y < y.length(); pos_y++) {
        int n = same_value(x, 0, y, pos_y);
        if (n > maxx) {
            maxx = n;
            pos_y_max = pos_y;
        }
    }
    return pos_y_max;
}

int main() {
    string x, y;
    cin >> x >> y;
    int pos_y_max = findpos_maxsame(x, y), pos_x_max = findpos_maxsame(y, x);
    int maxY = same_value(x, 0, y, pos_y_max), maxX = same_value(y, 0, x, pos_x_max);
    if (maxY < maxX || maxY == maxX && pos_x_max < pos_y_max) {
        cout << string(pos_x_max, '-') << y << endl;
        cout << maxX << endl;
    } else {
        cout << string(pos_y_max, '-') << x << endl;
        cout << maxY << endl;
    }
}*/