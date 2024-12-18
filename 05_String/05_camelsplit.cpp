#include <iostream>
#include <string>
using namespace std;
int main() {
    string input, output;
    cin >> input;
    for (int i = 0; i < input.length(); i++) {
        if (isupper(input[i]) || islower(input[i])) {
            output += input[i];
            if (!(islower(input[i + 1])))
                output += ", ";
        } else if (isdigit(input[i])) {
            output += input[i];
            if (!(isdigit(input[i + 1])))
                output += ", ";
        }
    }
    cout << output.substr(0, output.length() - 2);
}