// just test from Aj.solution
#include <iostream>
#include <string>
using namespace std;

string one[] = {"", " one", " two", " three", " four", " five", " six", " seven", " eight", " nine", " ten", " eleven", " twelve", " thirteen", " fourteen", " fifteen", " sixteen", " seventeen", " eighteen", " nineteen"};
string ten[] = {"", "", " twenty", " thirty", " forty", " fifty", " sixty", " seventy", " eighty", " ninety"};
string hun[] = {"", " thousand", " million", " billion", " trillion"};
// convert X-XXX
string convert3(string in) {
    int d1 = (in[2] - '0'), d10 = (in[1] - '0'), d100 = (in[0] - '0');
    int d2 = d10 * 10 + d1;
    string x; // check x or xx
    x = (d2 < 20) ? one[d2] : ten[d10] + one[d1];
    if (d100 != 0) x = one[d100] + " hundred" + x; // hun[] + xx
    return x;
}

int main() {
    string in;
    cin >> in;
    in = string((3 - in.length() % 3) % 3, '0') + in;
    string out; // 12345678 -> 012345678 ->loop 678 then 345 then 012
    for (int i = in.length() - 3, k = 0; i >= 0; i -= 3, k++) {
        string x = convert3(in.substr(i, 3));
        if (x != "") out = x + hun[k] + out;
    }
    if (out == "") out = " zero";
    cout << out.substr(1); // cut first space
}
