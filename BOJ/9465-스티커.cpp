// https://www.acmicpc.net/problem/9465

//시간제한  메모리
//1 초	256 MB

#include <iostream>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int n;
int map[2][100001];
int dp[2][100001];

int get_max(int a, int b) { return a > b ? a : b; }

int main() {
    FAIO;

    int t;
    cin >> t;
    while (t--) {
        memset(dp, 0, sizeof(dp));
        cin >> n;
        for (int i = 0; i < n; i++) cin >> map[0][i];
        for (int i = 0; i < n; i++) cin >> map[1][i];

        dp[0][0] = map[0][0];
        dp[1][0] = map[1][0];
        dp[0][1] = get_max(map[0][1] + map[1][0], map[0][0]);
        dp[1][1] = get_max(map[1][1] + map[0][0], map[1][0]);


        for (int i = 0; i < n; i++) {
            dp[0][i + 2] = map[0][i + 2] + get_max(dp[1][i], dp[1][i + 1]);
            dp[1][i + 2] = map[1][i + 2] + get_max(dp[0][i], dp[0][i + 1]);
        }

        cout << get_max(dp[0][n - 1], dp[1][n - 1]) << el;

    }

    return 0;
}


/*
    Algorithm : DP

    Time complexity : O(N)

*/