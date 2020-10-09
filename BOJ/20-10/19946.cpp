// https://www.acmicpc.net/problem/19946

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

unsigned long long N;

int main() {
    FAIO;

    cin >> N;
    int tmp = 0;

    if (N == 18446744073709551615) {
        cout << 64;
        return 0;
    }

    while (N >= 1) {
        if (N % 2 == 1) {
            N = N + 1;            
            while (N > 1) {
                N /= 2;
                tmp++;
            }
            break;
        }
        else N /= 2;
    }

    cout << tmp;
    return 0;
}
