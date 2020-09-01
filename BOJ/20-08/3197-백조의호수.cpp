// https://www.acmicpc.net/problem/3197

//시간제한  메모리
//1 초	256 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int b[2];
int r, c;
int map[1501][1501];
bool visited[1501][1501];
bool visited2[1501][1501];


int dx[4] = { 1 , 0 , -1 , 0 };
int dy[4] = { 0, 1 ,0 ,-1 };
queue<pair<int, int> > q;
queue<pair<int, int> > nextq;

bool bfsb() { // 백조 만나는지 탐색
    q.push(make_pair(b[0], b[1]));
    visited2[b[0]][b[1]] = true;

    while (!q.empty()) {
        pair<int, int> tmp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            pair<int, int> tmp2 = { tmp.first + dx[i], tmp.second + dy[i] };
            if (tmp2.first >= 0 && tmp2.first < r && tmp2.second >= 0 && tmp2.second < c) {
                if (!visited2[tmp2.first][tmp2.second] && map[tmp2.first][tmp2.second] == 0) {
                    q.push(tmp2);
                    visited2[tmp2.first][tmp2.second] = true;
                }
                else if (!visited2[tmp2.first][tmp2.second] && map[tmp2.first][tmp2.second] == 2) return true;
            }
            
        }
    }
    memset(visited2, false, sizeof(visited));
    return false;
}

void bfs(pair<int, int> start, int para) {
    if (para == 1) {
        while (!nextq.empty()) {
            q.push(nextq.front());
            nextq.pop();
        }        
    }
    else {
        q.push(start);
        visited[start.first][start.second] = true;
    }
    while (!q.empty()) {
        pair<int, int> tmp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            pair<int, int> tmp2 = { tmp.first + dx[i], tmp.second + dy[i] };
            if (tmp2.first >= 0 && tmp2.first < r && tmp2.second >= 0 && tmp2.second < c) {
                if (!visited[tmp2.first][tmp2.second] && (map[tmp2.first][tmp2.second] == 0 || map[tmp2.first][tmp2.second] == 2)) {
                    q.push(tmp2);
                    visited[tmp2.first][tmp2.second] = true;
                }
                else if (!visited[tmp2.first][tmp2.second] && map[tmp2.first][tmp2.second] == 1) {
                    map[tmp2.first][tmp2.second] = 0;
                    visited[tmp2.first][tmp2.second] = true;
                    nextq.push(tmp2);
                }
            }
        }
    }
}

int main() {
    FAIO;

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char a;
            cin >> a;
            if (a == '.') map[i][j] = 0;
            else if (a == 'X') map[i][j] = 1;
            else if (a == 'L') {
                map[i][j] = 2; // 백조 위치
                b[0] = i;
                b[1] = j;
            }
        }
    }

    int day = 0;
    if (bfsb()) {
        cout << day;
        return 0;
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] == 0 && !visited[i][j]) {
                nextq.push(make_pair(i, j));
                bfs(make_pair(i, j), 0);
            }
        }
    }

    memset(visited, false, sizeof(visited));
    day++;

    while (1) {
        if (bfsb()) {
            cout << day;
            return 0;
        }

        bfs(make_pair(1,1), 1);
        memset(visited, false, sizeof(visited));
        //cout << el;
        //for (int i = 0; i < r; i++) {
        //    for (int j = 0; j < c; j++) {
        //        cout << map[i][j];
        //    }
        //    cout << el;
        //}

        day++;
    }

    return 0;
}


/*
    Algorithm : BFS

    Time complexity : O(rc)

*/