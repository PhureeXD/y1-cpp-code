#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string line, char delimiter) {
    vector<string> v;
    string part;
    for (char c : line) {
        if (c == delimiter) {    // FOUND mean push part to v
            if (!part.empty()) { // prevent line have deli next to each other eg.(helloo....lo) (. have more than 1)
                v.push_back(part);
                part = "";
            }
        } else // NOT FOUND mean collect part
            part += c;
    }
    if (part.length() != 0) { // part.length()==0 is part.empty()
        v.push_back(part);
    }
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
