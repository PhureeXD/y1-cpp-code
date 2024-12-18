#include <iostream>
#include <string>
using namespace std;

int main() {
    char A[26], a[26];
    string input;
    for (char i = 'a'; i <= 'z'; i++) {
        a[i - 'a'] = i;
    }
    for (char i = 'A'; i <= 'Z'; i++) {
        A[i - 'A'] = i;
    }

    getline(cin, input);
    for (int i = 0; i < 26; i++) {
        int count = 0;
        for (int j = 0; j < input.size(); j++) {
            if (input[j] == a[i] || input[j] == A[i]) {
                count++;
            }
        }
        if (count > 0) {
            cout << a[i] << " -> " << count << endl;
        }
    }
}
