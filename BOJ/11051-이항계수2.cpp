// https://www.acmicpc.net/problem/11051

//시간제한  메모리
//1 초	256 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int dp[1002][1002];


int main() {
    FAIO;

    int n, k;

    cin >> n >> k;

    dp[1][0] = 1;
    dp[1][1] = 1;


    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        for (int j = 0; j <= i; j++) {
            dp[i + 1][j + 1] = (dp[i][j] + dp[i][j + 1])%10007;
            //cout << "dp[" << i+1 << "][" << j+1 << "] = " << dp[i + 1][j + 1] << el;
        }        
    }

    cout << dp[n][k];

    return 0;
}


/*
    Algorithm : DP

    Time complexity : O(N^2)

*/