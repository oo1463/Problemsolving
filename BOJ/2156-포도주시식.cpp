// https://www.acmicpc.net/problem/2156

//시간제한  메모리
//2 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int get_max(int a, int b) { return a > b ? a : b; }
int wine[10001];
int dp[10001];

int main() {
    FAIO;

    int n;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> wine[i];
    }

    dp[0] = 0;
    wine[0] = 0;
    dp[1] = wine[1];
    dp[2] = wine[1] + wine[2];

    for (int i = 3; i <= n; i++) {
        dp[i] = get_max(get_max(dp[i - 3] + wine[i - 1] + wine[i], wine[i] + dp[i - 2]), dp[i-1]);
        //cout << dp[i] << ' ';

    }

    cout << dp[n];

    return 0;
}


/*
    Algorithm : DP

    Time complexity : O(N)

*/