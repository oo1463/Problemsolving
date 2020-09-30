// https://www.acmicpc.net/problem/10026

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int N;
string s[101];
bool visited[101][101];
queue<pair<int, int> > q;
int cnt;

void bfs(int x, int y) {
    q.push(make_pair(x, y));
    visited[x][y] = true;

    while (!q.empty()) {
        pair<int, int> tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tx = tmp.first + dx[i];
            int ty = tmp.second + dy[i];

            if (tx >= 0 && tx < N && ty >= 0 && ty < N && !visited[tx][ty] && s[tmp.first][tmp.second] == s[tx][ty]) {
                
                visited[tx][ty] = true;
                q.push(make_pair(tx, ty));
            }
        }
    }
    cnt++;
}

int main() {
    FAIO;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s[i];        
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(!visited[i][j]) bfs(i, j);
        }
    }
    cout << cnt << ' ';

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) if (s[i][j] == 'G') s[i][j] = 'R';
    }

    memset(visited, false, sizeof(visited));
    cnt = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) bfs(i, j);
        }
    }

    cout << cnt;


    return 0;
}


/*
    Algorithm : BFS

    Time complexity : O(N^2)

*/