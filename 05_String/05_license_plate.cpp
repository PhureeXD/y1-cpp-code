#include <iostream>
#include <string>
using namespace std;
/*int main() {


    string input;
    int add;
    cin >> input >> add;

    int num = stoi(input.substr(4)) + add, part1 = num / 1000;
    // A00-000
    for (; part1 > 0; --part1) {
        char part1R = input[2] + 1;
        if (part1R > 'Z') {
            part1R = 'A';
            char part1M = input[1] + 1;
            if (part1M > 'Z') {
                part1M = 'A';
                input[0] += 1;
            }
            input[1] = part1M;
        }
        input[2] = part1R;
    }
    // A00-000
    string num_ans = to_string(num % 1000);
    if (num % 1000 < 10)
        num_ans = "00" + num_ans;
    else if (num % 1000 < 100)
        num_ans = "0" + num_ans;
    cout << input.substr(0, 4) << num_ans;
}*/
int main() {
    string in;
    cin >> in;
    int inn;
    cin >> inn; // 0AA-000
    int last = stoi(in.substr(4));
    int cal = (in[0] - '0') * 1000 * 26 * 26 + (in[1] - 'A') * 1000 * 26 + (in[2] - 'A') * 1000 + last + inn;
    string num = "00" + to_string(cal % 1000);
    // 1AB-123
    cal /= 1000;                               // 1AB
    string out = to_string((cal / (26 * 26))); // 1
    out += char(cal / 26 % 26 + 'A');          // A
    out += char(cal % 26 + 'A');               // B
    cout << out << '-' << num.substr(num.length() - 3);
}