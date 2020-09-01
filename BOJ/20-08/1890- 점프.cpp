// https://www.acmicpc.net/problem/1890

//시간제한  메모리
//1 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
//#include <queue>

#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N;
int board[101][101];
long long dp[101][101];
bool is_poss[101][101];
//queue<pair<int, int>> q;

//void bfs() {
//    q.push(pair<int, int>(1, 1));
//    dp[1][1] = 1;
//
//    while (!q.empty()) {
//        pair<int, int> tmp = q.front();
//        q.pop();
//
//        if (board[tmp.first][tmp.second] == 0) continue;
//
//        pair<int, int> tmp1 = tmp;
//        pair<int, int> tmp2 = tmp;
//
//        tmp1.first += board[tmp.first][tmp.second];
//        tmp2.second += board[tmp.first][tmp.second];
//
//        if (tmp1.first <= N) {
//            q.push(tmp1);
//            dp[tmp1.first][tmp1.second] += dp[tmp.first][tmp.second];
//        }
//        if (tmp2.second <= N) {
//            q.push(tmp2);
//            dp[tmp2.first][tmp2.second] += dp[tmp.first][tmp.second];
//        }
//    }
//}

int main() {
    FAIO;
    memset(dp, 0, sizeof(dp));

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }
    dp[1][1] = 1;
    is_poss[1][1] = true;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (board[i][j] != 0 && is_poss[i][j]) {
                dp[i + board[i][j]][j] += dp[i][j];
                dp[i][j + board[i][j]] += dp[i][j];
                is_poss[i + board[i][j]][j] = true;
                is_poss[i][j + board[i][j]] = true;
            }
        }
    }

    cout << dp[N][N];
    return 0;
}

/*
    Algorithm : Dinamic Programming

    Time complexity : O(N^2)

*/