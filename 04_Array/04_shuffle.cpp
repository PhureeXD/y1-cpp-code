#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string deck[n];
    for (int i = 0; i < n; i++) {
        cin >> deck[i];
    }
    string act, deck1[n];
    cin.ignore();
    getline(cin, act);
    int med = n / 2;
    for (auto c : act) {
        for (int i = 0; i < n; i++) {
            deck1[i] = deck[i]; /*this tempo has to be
            in loop to have the current deck after 1 act*/
        }

        if (c == 'C') {
            for (int i = 0; i < med; i++) { // right side use tempo
                deck[i] = deck1[med + i];
                deck[med + i] = deck1[i];
            }
        } else if (c == 'S') {
            for (int i = 0; i < med; i++) { // right side use tempo
                deck[i * 2] = deck1[i];
                if (i > 0) {
                    deck[2 * i - 1] = deck1[med + (i - 1)];
                }
            }
        }
    }

    for (auto z : deck) {
        cout << z << " ";
    }
}