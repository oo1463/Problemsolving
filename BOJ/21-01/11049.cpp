// https://www.acmicpc.net/problem/11049

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int dp[501][501];

int mn(int a, int b) { return a<b?a:b;}

int main() {
    FAIO;

    int N , r, c;
    int mat[501][2];

    memset(dp,-1 ,sizeof(dp));
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> mat[i][0] >> mat[i][1];
    }
    for(int i=0; i<N; i++) dp[i][i] = 0;

    // for(int i=0;i<N-1; i++) dp[i][i+1] = mat[i][0] * mat[i][1] * mat[i+1][1];



    for(int i=N-2; i>=0; i--){
        for(int j=i+1; j<N; j++){
            dp[i][j] = mn(dp[i+1][j] + mat[i][0] * mat[i+1][0] * mat[j][1], dp[i][j-1] + mat[i][0] * mat[j-1][1] * mat[j][1]);
        }
    }

    // for(int i=0; i<N; i++){
    //     for(int j=0; j<N; j++) cout << dp[i][j] << ' ';
    //     cout << el;
    // }


    cout << dp[0][N-1];

    return 0;
}



/*
    Algorithm : DP

    Time complexity : O(N^2)
    
*/
