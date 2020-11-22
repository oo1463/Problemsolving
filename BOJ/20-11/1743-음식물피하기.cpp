// https://www.acmicpc.net/problem/1743

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, M, k;
bool map[101][101];
queue<pair<int,int> > q;
bool visited[101][101];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int mxCnt = 0;

void bfs(int r, int c) {
    q.push(make_pair(r, c));
    int cnt = 0;

    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        cnt++;

        for (int i = 0; i < 4; i++) {
            int tmpx = front.first + dx[i];
            int tmpy = front.second + dy[i];

            if (!visited[tmpx][tmpy] && tmpx > 0 && tmpx <= N && tmpy > 0 && tmpy <= M && map[tmpx][tmpy] == true) {
                visited[tmpx][tmpy] = true;
                q.push(make_pair(tmpx, tmpy));
                
            }
        }
    }
    if (cnt > mxCnt) mxCnt = cnt;

}

int main() {
    FAIO;

    cin >> N >> M >> k;
    int r, c;
    while (k--) {
        cin >> r >> c;
        map[r][c] = true;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (!visited[i][j] && map[i][j] == true) {
                visited[i][j] = true;
                bfs(i, j);
            }
        }
    }

    cout << mxCnt;

    return 0;
}


/*
    Algorithm : bfs

    Time complexity : O(NM)

*/