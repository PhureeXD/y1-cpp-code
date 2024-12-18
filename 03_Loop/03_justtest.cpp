#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    for (size_t i = 0; i < n; i++) {
        string line, lineinput;
        getline(cin, lineinput);
        for (char c : lineinput) {
            if (c != ' ') {
                line += c;
            }
        }

        string even, odd;
        int count_r = 0;
        for (size_t i = 0; i < line.length(); i++) {
            if (i % 2 == 0) {
                even += line[i];
                if (line[i] == 'R') {
                    count_r++;
                }
            } else {
                odd += line[i];
            }
        }
        string sq = "YGNBPK";
        bool ok = true;
        if (line[0] != 'R') {
            ok = false;
        } else if (odd.find('R') != string::npos) //
        {
            ok = false;
        } else if (even.find_last_of('R') != count_r - 1) {
            ok = false;
        } else {
            int last_r = line.find_last_of('R');
            if (last_r != (line.length() - 1)) {
                for (int i = last_r + 2; i < line.length(); i++) {
                    if (line[i] != sq[i - (last_r + 2)]) {
                        ok = false;
                    }
                }
            }
        }

        int point = 0;
        if (ok) {
            for (auto b : line) {
                if (b == 'R') {
                    point += 1;
                } else {
                    point += 2 + sq.find(b);
                }
            }
            cout << point << endl;
        } else {

            cout << "WRONG_INPUT" << endl;
        }
    }
}