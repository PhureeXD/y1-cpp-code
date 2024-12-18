#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, ss, sss = " ";
    int same = 0;
    getline(cin, ss); // keyword
    getline(cin, s);  // sentence
    sss = sss + s + sss;
    int slen = ss.length();
    int pos = sss.find(ss);

    while (pos != string::npos) {
        char a = sss[pos - 1];
        char b = sss[pos + slen];
        pos = sss.find(ss, pos + 1);
        if ((a == '\"' || a == '(' || a == ')' || a == ',' || a == '.' || a == '\'' || a == ' ') && (b == '\"' || b == '(' || b == ')' || b == ',' || b == '.' || b == '\'' || b == ' ')) {
            same++;
        }
    }
    cout << same;
}