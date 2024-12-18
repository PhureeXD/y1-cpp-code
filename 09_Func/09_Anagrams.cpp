#include <bits/stdc++.h>
using namespace std;

void Anagram(string prefix, string input, set<string> &data) {
    if (input.empty()) {
        data.insert(prefix);
        return;
    }
    for (int i = 0; i < input.length(); i++) { // cpp //c,pp cp,p cpp,"" insert!
        string prefix2 = prefix + input[i];    // p,cp pc,p pcp,"" insert!
        string input2 = input.substr(0, i) + input.substr(i + 1);
        Anagram(prefix2, input2, data);
    }
}

int main() {
    string input;
    cin >> input;
    set<string> data;
    Anagram("", input, data);
    for (auto s : data) {
        cout << s << ' ';
    }
}