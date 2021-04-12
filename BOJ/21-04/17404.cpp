// https://www.acmicpc.net/problem/17404

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N;
int color[1001][3];
int dp[1001][3];

int mn(int a, int b) {return a>b?b:a;}

int main() {
    FAIO;

    cin >> N;
    for(int i=0; i<N; i++) cin >> color[i][0] >> color[i][1] >> color[i][2];
    int mnn = 10e7;

    for(int i=0; i<N; i++){
        dp[i][0] = 10e7;
        dp[i][1] = 10e7;
        dp[i][2] = 10e7;
    }

    dp[0][0] = color[0][0];  // 1번 집을 r로 고정
    dp[0][1] = 10e7;
    dp[0][2] = 10e7;
    

    for(int i=1; i<N; i++){
        dp[i][0] = mn(dp[i-1][1] + color[i][0] , dp[i-1][2] + color[i][0]);
        dp[i][1] = mn(dp[i-1][0] + color[i][1] , dp[i-1][2] + color[i][1]);
        dp[i][2] = mn(dp[i-1][0] + color[i][2] , dp[i-1][1] + color[i][2]);
    }

    mnn = mn(dp[N-1][1], dp[N-1][2]);

    dp[0][0] = 10e7;  // 1번 집을 g로 고정
    dp[0][1] = color[0][1];
    dp[0][2] = 10e7;
    
    for(int i=1; i<N; i++){
        dp[i][0] = mn(dp[i-1][1] + color[i][0] , dp[i-1][2] + color[i][0]);
        dp[i][1] = mn(dp[i-1][0] + color[i][1] , dp[i-1][2] + color[i][1]);
        dp[i][2] = mn(dp[i-1][0] + color[i][2] , dp[i-1][1] + color[i][2]);
    }

    mnn = mn(mn(dp[N-1][0], dp[N-1][2]), mnn);

    dp[0][0] = 10e7;  // 1번 집을 b로 고정
    dp[0][1] = 10e7;
    dp[0][2] = color[0][2];
    
    for(int i=1; i<N; i++){
        dp[i][0] = mn(dp[i-1][1] + color[i][0] , dp[i-1][2] + color[i][0]);
        dp[i][1] = mn(dp[i-1][0] + color[i][1] , dp[i-1][2] + color[i][1]);
        dp[i][2] = mn(dp[i-1][0] + color[i][2] , dp[i-1][1] + color[i][2]);
    }

    mnn = mn(mn(dp[N-1][0], dp[N-1][1]), mnn);

    cout << mnn;
   
    return 0;
}



/*
    Algorithm : dp

    Time complexity : O(N)
    
*/
