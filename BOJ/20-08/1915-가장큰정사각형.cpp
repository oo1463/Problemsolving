// https://www.acmicpc.net/problem/1915

//시간제한  메모리
//2 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <math.h>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int get_min(int a, int b) { return a < b ? a : b; }

string s[1002];
int map[1002][1002];
int dp[1002][1002];

int main() {
    FAIO;

    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            map[i][j+1] = s[i][j] - 48;
        }
    }
    int ans = 0;

    memcpy(dp, map, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] == 1) {
                int a = get_min(dp[i - 1][j - 1], get_min(dp[i - 1][j], dp[i][j - 1]));
                dp[i][j] = a + 1;
            }                
            ans = max(ans, dp[i][j]);
        }
    }

    //for (int i = 1; i <= n; i++) {
    //    for (int j = 1; j <= m; j++) {
    //        cout << dp[i][j] << ' ';
    //    }
    //    cout << el;
    //}


    cout << ans*ans;
    return 0;
}


/*
    Algorithm : dp

    Time complexity : O(N^2)

*/