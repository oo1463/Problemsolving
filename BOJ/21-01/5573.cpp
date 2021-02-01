// https://www.acmicpc.net/problem/5573

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int W,H,N;
bool map[1001][1001];
bool n_map[1001][1001];
int dp[1001][1001];

int main() {
    FAIO;

    cin >> H >> W >> N;

    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            cin >> map[i][j];
        }
    }

    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            if(i==1 && j == 1) dp[i][j] = N-1;
            else {
                dp[i][j] = dp[i][j-1]/2 + dp[i-1][j]/2;

                if(map[i][j-1] && dp[i][j-1] % 2 == 1){
                    dp[i][j]++;
                }
                
                if(!map[i-1][j] && dp[i-1][j] % 2 == 1){
                    dp[i][j]++;
                }
            }

            if(dp[i][j] % 2 == 1){
                n_map[i][j] = !map[i][j];
            }
            else{
                n_map[i][j] = map[i][j];
            }

        }
    }

    int x=1 ,y = 1;

    while(x <= H && y <= W){
        if(n_map[x][y] == false){
            n_map[x][y] = true;
            x++;
        }
        else if(n_map[x][y] == true){
            n_map[x][y] = false;
            y++;
        }
    }

    cout << x << ' ' << y;


   
    return 0;
}



/*
    Algorithm : DP

    Time complexity : O(W*H)
    
*/
