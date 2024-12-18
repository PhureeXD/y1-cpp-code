#include <iostream>
#include <string>
using namespace std;
int main() {
    string input;
    while (getline(cin, input)) {
        string output;
        char secret = input[input.length() - 1];
        int first = 0, last = -1;
        while (first != string::npos) {
            first = input.find(secret, last + 1);
            last = input.find(secret, first + 1);
            if (last == string::npos)
                break;
            output += input.substr(first + 1, last - first - 1);
        }
        cout << output << endl;
    }
}