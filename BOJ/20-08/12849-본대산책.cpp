// https://www.acmicpc.net/problem/12849

//시간제한  메모리
//1 초	512 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int d;
int adj[9][9] = { { 0,0,0,0,0,0,0,0,0 }, {0,0,1,1,0,0,0,0,0}, {0,1,0,1,1,0,0,0,0}, {0,1,1,0,1,1,0,0,0},{0,0,1,1,0,1,1,0,0},{0,0,0,1,1,0,1,1,0},{0,0,0,0,1,1,0,0,1},{0,0,0,0,0,1,0,0,1},{0,0,0,0,0,0,1,1,0,} };
long long dp[100001][9];

int main() {
    FAIO;

    cin >> d;
    dp[1][2] = 1;
    dp[1][3] = 1;

    for (int i = 1; i < d; i++) {
        for (int j = 1; j <= 8; j++) {
            for (int k = 1; k <= 8; k++) {
                if (adj[j][k] == 1) dp[i + 1][j] += dp[i][k];                
            }
            dp[i + 1][j] = dp[i + 1][j] % 1000000007;
        }
    }

    cout << dp[d][1] % 1000000007;


    return 0;
}


/*
    Algorithm : DP

    Time complexity : O(d)

*/