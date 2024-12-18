// Spoonerism
#include <iostream>
#include <string>
using namespace std;
/*bool isvowel(char c) {
    char vo[5] = {'a', 'e', 'i', 'o', 'u'};

    for (int i = 0; i < 5; i++) {
        if (c == vo[i]) return 1;
    }
    return 0;
}
int main() {
    string input;
    getline(cin, input);
    // scan from Left to mid,// f1 l1 | f2 l2
    int f1 = 0;
    while (!isvowel(input[f1]))
        f1++;
    int l1 = f1 + 1; // got first vowel word pos
    while (input[l1] != ' ')
        l1++;
    // now scan from Right to mid,// f1 l1 | f2 l2
    int f2 = input.length() - 1;
    while (input[f2] == ' ')
        f2--;
    input = input.substr(0, f2 + 1);

    while (input[f2] != ' ')
        f2--;
    int l2 = f2 + 1; // got first last word pos
    while (!isvowel(input[l2]))
        l2++;
    // Concatenate// f1 l1 | f2 l2
    string output1 = input.substr(0, f1) + input.substr(l2);                // first reverse word
    string output2 = input.substr(l1, l2 - l1) + input.substr(f1, l1 - f1); // last reverse word
    cout << output1 + output2;
}*/
bool isvowel(char c) {
    char v[] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < sizeof(v) / sizeof(v[0]); i++) {
        if (c == v[i]) return 1;
    }
    return 0;
}
int main() {
    string input;
    getline(cin, input);
    // f1 v1----f2 v2
    // find *pos* first of L and first of R
    int f1 = 0, f2 = input.length() - 1;
    while (!isvowel(input[f1]))
        f1++;
    while (input[f2] != ' ' || f2 == input.length() - 1)
        f2--;
    // find *pos* second part of L ,R
    int v1 = f1 + 1, v2 = f2 + 1; // v1,v2 start after that
    while (input[v1] != ' ')
        v1++;
    while (!isvowel(input[v2]))
        v2++;
    string output1 = input.substr(0, f1) + input.substr(v2);
    string output2 = input.substr(v1, v2 - v1)    // second word til before last word
                     + input.substr(f1, v1 - f1); // reverse from the first word at start
    cout << output1 + output2;
}