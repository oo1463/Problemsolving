
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N;

int main() {
    FAIO;

    cin >> N;

    if (N == 0) cout << 1;
    else if(N > 0){
        int bit = 1;
        while (N/2 >= 1) {
            bit++;
            N = N / 2;
        }
        cout << bit;
    }
    else if (N < 0) {
        cout << 32;
    }

    return 0;
}
