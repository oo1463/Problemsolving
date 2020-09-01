// https://www.acmicpc.net/problem/11047

//시간제한  메모리
//1 초	256 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int n, k;
int coin[11];

int main() {
    FAIO;
    int cnt = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        if (k / coin[i] != 0) {
            cnt += k / coin[i];
            k = k % coin[i];
        }
    }

    cout << cnt;

    return 0;
}


/*
    Algorithm : Greedy
    
    Time complexity : O(n)

*/