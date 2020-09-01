// https://www.acmicpc.net/problem/17070

//시간제한  메모리
//1 초 (추가 시간 없음)	512 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N;
int map[17][17];
int dp[3][17][17];

int main() {
    FAIO;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    dp[0][1][2] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 3; j <= N; j++) {
            
            dp[0][i][j] = dp[2][i][j - 1] + dp[0][i][j - 1];
            dp[1][i][j] = dp[2][i - 1][j] + dp[1][i - 1][j];
            dp[2][i][j] = dp[0][i - 1][j - 1] + dp[1][i - 1][j - 1] + dp[2][i - 1][j - 1];
            if (map[i - 1][j] == 1) {
                dp[1][i][j] = 0;
                dp[2][i][j] = 0;
            }
            if (map[i][j - 1] == 1) {
                dp[0][i][j] = 0;
                dp[2][i][j] = 0;
            }
            if (map[i][j] == 1) {
                dp[0][i][j] = 0;
                dp[1][i][j] = 0;
                dp[2][i][j] = 0;
            }
        }
    }

    /*for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << dp[0][i][j]<< dp[1][i][j]<<  dp[2][i][j] << ' ';
        }
        cout << el;
    }*/
    cout << dp[0][N][N] + dp[1][N][N] + dp[2][N][N];

    return 0;
}


/*
    Algorithm : DP

    Time complexity : O(N^2)

*/