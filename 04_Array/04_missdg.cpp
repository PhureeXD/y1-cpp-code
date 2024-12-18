#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, aa, num = "0123456789";
    bool b[11] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    getline(cin, a);

    for (int c = 0; c < 10; c++) // num[c]
    {
        for (char d : a) // string
        {
            if (num[c] == d) {
                b[c] = false; // has 0-9 = false
            }
        }
    }
    for (int e = 0; e < 10; e++) {
        if (b[e]) // true -> dont have 0-9
        {
            aa += num[e];
            aa += ',';
            b[10] = false; // after that if it mean at least 1 true so None case = false
        }
    }

    if (!(b[10])) // None case =true
    {
        cout << aa.substr(0, aa.length() - 1); // cut the "," in the end
    } else                                     // None case
    {
        cout << "None";
    }
}
