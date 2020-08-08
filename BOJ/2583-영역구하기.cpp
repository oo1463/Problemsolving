// https://www.acmicpc.net/problem/2583

//시간제한  메모리
//1 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

bool visited[101][101];
bool filled[101][101];

int dx[4] = { 1 , 0 ,-1 ,0 };
int dy[4] = { 0, 1, 0, -1 };

int n, m, k;
queue<pair<int, int>> q;
vector<int> v;

void bfs(int x, int y) {
    pair<int, int> tmp = pair<int, int>(x, y);
    q.push(tmp);
    visited[tmp.first][tmp.second] = true;
    int cnt = 1;
    while (!q.empty()) {

        tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = tmp.first + dx[i];
            int y = tmp.second + dy[i];
            if (x >= 0 && y >= 0 && x < n && y < m && !visited[x][y]) {
                if (filled[x][y] == false) {
                    q.push(pair<int, int>(x, y));
                    visited[x][y] = true;
                    cnt++;
                }                
            }
        }
    }
    v.push_back(cnt);
}


int main() {
    FAIO;
    int pos[4];
    int cnt = 0;
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        cin >> pos[0] >> pos[1] >> pos[2] >> pos[3];
        for (int j = pos[0]; j < pos[2]; j++) {
            for (int k = pos[1]; k < pos[3]; k++) filled[k][j] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!filled[i][j] && !visited[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    sort(v.begin(), v.end());

    cout << cnt << el;
    for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';

    return 0;
}


/*
    Algorithm : BFS

    Time complexity : O(N^3)

*/