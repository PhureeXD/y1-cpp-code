#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    while (N != 1) {
        for (size_t i = 2; i <= N; i++) {
            while (N % i == 0) {
                cout << i;
                N /= i;
                if (N != 1) {
                    cout << "*";
                }
            }
        }
    }
}
