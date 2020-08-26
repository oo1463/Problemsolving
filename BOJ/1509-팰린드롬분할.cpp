// https://www.acmicpc.net/problem/10942

//시간제한  메모리
//0.5 초	256 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, M;
int dp[2501][2501];
int s[2501];
int d[2501];
string s2;

int main() {
    FAIO;

    //cin >> N;
    cin >> s2;
    N = s2.length();
    for (int i = 1; i <= N; i++) s[i] = s2[i - 1] - 'A';

    for (int i = 1; i <= N; i++) {
        for (int j = i; j > 0; j--) dp[i][j] = -1;
        dp[i][i] = 1;
    }

    for (int i = N; i > 0; i--) {
        for (int j = i + 1; j <= N; j++) {
            if ((dp[i + 1][j - 1] >= 1 || dp[i + 1][j - 1] == -1) && s[i] == s[j]) {
                if (dp[i + 1][j - 1] == -1) dp[i][j] = 2;
                else dp[i][j] = dp[i + 1][j - 1] + 2;
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) d[i] = 2501;
    d[0] = 0;
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= j; i++) {
            if (dp[i][j] >= 1) {
                if (d[j] > d[j - dp[i][j]] + 1) d[j] = d[j - dp[i][j]] + 1;
            }
        }
    }

    cout << d[N];

    //for (int i = 1; i <= N; i++) {
    //    for (int j = 1; j <= N; j++) cout << dp[i][j] << ' ';
    //    cout << el;
    //}

    return 0;
}


/*
    Algorithm : DP

    Time complexity : O(length^2)

*/