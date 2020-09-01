// https://www.acmicpc.net/problem/1520

//시간제한  메모리
//2 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int cnt = 0;
int M, N;
int map[501][501];
int dp[501][501];

int dx[4] = { 0 , 0 ,1 , -1 };
int dy[4] = { 1, -1, 0 , 0 };

int dfs(int x, int y) {
    
    if (x == 1 && y == 1) {
        return 1;
    }
   
    if (dp[x][y] == -1) {
        dp[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int tmpx = x + dx[i];
            int tmpy = y + dy[i];
            if (tmpx <= M && tmpy <= N && tmpx >= 1 && tmpy >= 1 && map[x][y] < map[tmpx][tmpy]) {
                dp[x][y] += dfs(tmpx, tmpy);
            }
        }
    }
    return dp[x][y];
}

int main() {
    FAIO;

    cin >> M >> N;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << dfs(M, N);
    return 0;
}


/*
    Algorithm : DFS , DP

    Time complexity : O(NM)

*/