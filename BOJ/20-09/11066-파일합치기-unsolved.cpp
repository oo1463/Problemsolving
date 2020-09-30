// https://www.acmicpc.net/problem/11066

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int mn(int a, int b) { return a < b ? a:b; }

int main() {
    FAIO;
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        int file[501];
        int dp[501];
        int sum[501];
        for (int i = 1; i <= N; i++) cin >> file[i];

        dp[0] = 0;
        sum[0] = 0;
        dp[1] = 0;
        sum[1] = file[1];
        
        for (int i = 2; i <= N; i++) {
            sum[i] = sum[i - 1] + file[i];
            dp[i] = mn(dp[i-1] + sum[i], sum[i] + dp[i - 2]);
        }

        for (int i = 1; i <= N; i++)  cout << dp[i] << ' ';
        cout << endl;
    }

    return 0;
}


/*
    Algorithm :

    Time complexity : O(N^2)

*/