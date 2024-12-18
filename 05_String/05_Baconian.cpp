#include <iostream>
#include <string>
using namespace std;

string code[] = {"UUUU", "UUUL", "UULU", "UULL", "ULUU", "ULUL", "ULLU", "ULLL", "LUUU", "LUUL", "LULU", "LULL"};
char real[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', ','};
string decode(string s) {
    string s2, returnn;
    for (int i = 0; i < s.length(); i++) {
        if (isalpha(s[i])) {
            s2 += (isupper(s[i])) ? 'U' : 'L';
            for (int k = 0; k < 12; k++) {
                if (s2 == code[k]) {
                    returnn += real[k];
                    s2 = "";
                    break;
                }
            }
        }
    }
    return returnn;
}
string encode(string s, string send) {
    string codee = "";
    for (int i = 0; i < send.length(); i++) {
        for (int j = 0; j < 12; j++) {
            if (send[i] == real[j]) {
                codee += code[j];
            } // 34-20->UULL
        }
    }
    int alpha = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isalpha(s[i])) alpha++;
    }
    int n = send.length() * 4; //! alpha need to = n
    if (n > alpha) {
        for (int i = 0; i < 9999; i++) {
            s += s[i % s.length()];
            if (isalpha(s[i % s.length()])) ++alpha;
            if (alpha == n) break;
        }
    }
    for (int i = 0, j = 0; i < n; j++) {
        // static i //j skipping
        if (isalpha(s[j])) {
            if (codee[i] == 'U') {
                s[j] = toupper(s[j]);
            } else if (codee[i] == 'L') {
                s[j] = tolower(s[j]);
            }
            i++;
        }
    }
    return s;
}

int main() {
    string lang, cmd, send;
    getline(cin, lang);
    while (getline(cin, send)) {
        cmd = send.substr(0, 1);
        send = send.substr(2);
        if (cmd == "E") {
            cout << encode(lang, send) << endl;
        } else {
            cout << decode(send) << endl;
        }
    }
}