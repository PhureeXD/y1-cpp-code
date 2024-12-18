#include <cmath>
#include <iostream>
using namespace std;
int main() {
    int k, A, N, B, M;
    bool state = false;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> A >> N >> B >> M;
        if (0 <= A && 0 <= B && A <= 9 && B <= 9 && N > 0 && M > 0 && 2 <= N + M && N + M <= 17)
            state = true;
        long long num = 0;
        for (int i = 0; i < M; i++) {
            num += B * (long long)pow(10, i);
        }
        for (int i = 0; i < N; i++) {
            num += A * (long long)pow(10, i + M);
        }
        for (long long i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                state = false;
                break;
            }
        }
        if (state)
            cout << "YES" << endl;
        else {
            cout << "NO" << endl;
        }
    }
}