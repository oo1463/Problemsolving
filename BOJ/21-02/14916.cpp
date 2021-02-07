// https://www.acmicpc.net/problem/14916

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int n;
int dp[100000];

int mn(int a, int b) {return a<b?a:b;}

int main() {
    FAIO;
    
    cin >> n;

    dp[1] = -1;
    dp[2] = 1;
    dp[3] = -1;
    dp[4] = 2;
    dp[5] = 1;
    dp[6] = 3;
    dp[7] = 2;
    dp[8] = 4;
    dp[9] = 3;

    for(int i=10; i<=n; i++){
        dp[i] = mn(dp[i-2]+1, dp[i-5]+1);
    }
    
    cout << dp[n];

    return 0;
}



/*
    Algorithm : dp

    Time complexity : O(N)
    
*/
