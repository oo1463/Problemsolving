// https://www.acmicpc.net/problem/1028

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int R,C;
string map[751];
int dp[752][752][2];

int main() {
    FAIO;

    cin >> R >> C;

    memset(dp,0,sizeof(dp));
    for(int i=0; i<R; i++){
        cin >> map[i];

        for(int j=0; j<C; j++){
            if(map[i][j] == '1'){
                dp[i+1][j+1][0] = dp[i][j][0] + map[i][j]-'0';
                dp[i+1][j+1][1] = dp[i][j+2][1] + map[i][j]-'0';
            }
        }
    }

    int mx = 0;

    for(int i=R; i>0; i--){
        for(int j=C; j>0; j--){
            int diamond_size;
            diamond_size = min(dp[i][j][0], dp[i][j][1]);   
            for(int k = diamond_size; k > mx; k--){
                if(dp[i - k + 1][j - k + 1][1] >= k && dp[i-k + 1][j+k-1][0] >= k){
                    mx = k;
                    break;
                }
            }
        }
    }

    cout << mx;
   
    return 0;
}

/*
    Algorithm : DP

    Time complexity : O(N^2)
    
*/
