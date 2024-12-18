#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    int useless, in;
    cin >> useless;
    while (cin >> in) {
        if (in == -1)
            break;
        if (in == ' ') continue;
        v.push_back(in);
    }
    if (v.empty()) {
        cout << "[]";
    } else {
        string out;
        if (v.size() % 2 == 0) {
            for (auto itr = v.rbegin(); itr < v.rend(); itr += 2) {
                out += to_string(*itr) + ", ";
            }
        } else {
            for (auto itr = v.rbegin() + 1; itr < v.rend() - 1; itr += 2) {
                out += to_string(*itr) + ", ";
            }
        }
        for (auto itr = v.begin(); itr < v.end(); itr += 2) {
            out += to_string(*itr) + ", ";
        }

        cout << "[" + out.substr(0, out.length() - 2) << "]";
    }
}