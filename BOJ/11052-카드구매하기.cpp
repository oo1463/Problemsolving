// https://www.acmicpc.net/problem/11052

//시간제한  메모리
//1 초	256 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
;
using namespace std;

int p[1001];
int dp[1001];

int main() {
    FAIO;

    int n;
    int maxx = 0;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    p[0] = 0;
    dp[0] = 0;
    dp[1] = p[1];

    for (int i = 2; i <= n; i++) {
        maxx = 0;
        for (int j = 1; j <= i; j++) {
            if (maxx < dp[i - j] + p[j]) maxx = dp[i - j] + p[j];
        }
        dp[i] = maxx;
    }

    cout << dp[n];

    return 0;
}


/*
    Algorithm : DP

    Time complexity : O(n(n+1)/2) --> O(n^2)

*/