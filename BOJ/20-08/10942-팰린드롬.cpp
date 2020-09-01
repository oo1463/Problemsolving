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

int N,M;
int dp[2001][2001];
int a[2001];

int main() {
    FAIO;
    
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i];

    for (int i = 1; i <= N; i++) {
        for (int j = i; j > 0; j--) dp[i][j] = -1;
        dp[i][i] = 1;
    }

    for (int i = N; i > 0; i--) {
        for (int j = i + 1; j <= N; j++) {
            if ((dp[i + 1][j - 1] == 1 || dp[i + 1][j - 1] == -1) && a[i] == a[j]) dp[i][j] = 1;
        }
    }
    

    cin >> M;
    while (M--) {
        int S, E;
        cin >> S >> E;
        cout << dp[S][E] <<el;
    }

    return 0;
}


/*
    Algorithm : DP

    Time complexity : O(N^2 + M)

*/