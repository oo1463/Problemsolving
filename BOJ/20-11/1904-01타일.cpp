// https://www.acmicpc.net/problem/1904

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int dp[1000001];
int N;

int main() {
    FAIO;

    cin >> N;
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;
    }

    cout << dp[N];

    return 0;
}


/*
    Algorithm : dp

    Time complexity : O(N)

*/