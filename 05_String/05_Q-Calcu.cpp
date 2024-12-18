// #include <cmath>
#include <iostream>
#include <string>
using namespace std;
string Add(string a, string b) {
    int n = max(a.length(), b.length());
    a = string(n - a.length(), '0') + a;
    b = string(n - b.length(), '0') + b;
    int carry = 0;
    string current;
    for (int i = n - 1; i >= 0; i--) {
        int cal = a[i] - '0' + b[i] - '0' + carry;
        current = (char)(cal % 10 + '0') + current;
        carry = cal / 10;
    }               // int+'0'=char that number ,charthatisnum -'0'=intthatchar
    if (carry != 0) // the leftest
    {
        current = char(carry + '0') + current;
    }
    return current;
}
int main() {
    string input, sum;
    // new=old+new
    while (cin >> input) {
        if (input == "END") break;
        sum = Add(input, sum);
    }
    cout << sum;
}
