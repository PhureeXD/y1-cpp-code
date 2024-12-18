#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cin >> n;
    string ct[n];
    int cost[n];
    for (int i = 0; i < n; i++) {
        cin >> ct[i] >> cost[i];
    }
    string code[25];
    int ii = 0, pos = 0, sum = 0;
    while (cin >> code[ii]) {
        pos = code[ii].find("-");
        code[ii] = code[ii].substr(pos + 1, 2);
        // now we got only keyword in code[]
        for (int i = 0; i < n; i++) {
            if (code[ii] == ct[i]) {
                sum += cost[i];
                //"TH"->"TH"= 0
                if (code[ii - 1] == code[ii]) {
                    sum -= cost[i];
                }
            }
            if (ii == 0)
                sum = 0;
        }
        ii++;
    }

    cout << sum;
}