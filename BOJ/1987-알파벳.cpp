// https://www.acmicpc.net/problem/1987

//시간제한  메모리
//2 초	256 MB

#include <iostream>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int R, C;
int map[21][21];
int visited[27] = { false };

int mx = 0;
int dx[4] = { 1, 0 , -1, 0 };
int dy[4] = { 0 , 1 , 0 , -1 };

void dfs(int x, int y, int cnt) {
    for (int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];

        if (tx > 0 && ty > 0 && tx <= R && ty <= C && !visited[map[tx][ty]]) {
            //cout << tx << ' ' << ty << el;

            visited[map[tx][ty]] = true;
            dfs(tx, ty, cnt + 1);
            visited[map[tx][ty]] = false;
        }
        if (mx < cnt) mx = cnt;
    }

}

int main() {
    FAIO;

    string s[21];

    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        cin >> s[i];
        for (int j = 1; j <= C; j++) map[i][j] = s[i][j-1] - 'A' + 1;
    }

    visited[map[1][1]] = true;
    dfs(1, 1, 1);
    cout << mx;

    return 0;
}


/*
    Algorithm : DFS

    Time complexity : O(2^26)

*/