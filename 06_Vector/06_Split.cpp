#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> split(string line, char delimiter) {
    vector<string> v;
    int pos = 0, first = 0, found = line.find(delimiter, pos);
    while (found != string::npos) {
        string check = line.substr(first, found - first);
        if (check.length() != 0)
            v.push_back(check);
        pos = found + 1;
        first = pos;
        found = line.find(delimiter, pos);
    }
    string check2 = line.substr(first);
    if (check2.length() != 0)
        v.push_back(check2);
    return v;
}
int main() {
    string line;
    getline(cin, line);
    string delim;
    getline(cin, delim);
    for (string e : split(line, delim[0])) {
        cout << '(' << e << ')';
    }
}