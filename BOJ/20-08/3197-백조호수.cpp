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
queue<pair<int, int> > q;
queue<pair<int, int> > nextq;

int dx[4] = { 1 , 0 , -1 , 0 };
int dy[4] = { 0, 1 ,0 ,-1 };

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
    memset(visited2, false, sizeof(visited2));
    return false;
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

    int date = 0;
    while (1) {
        if (bfsb()) {
            cout << date;
            return 0;
        }

        int tmpi;
        int tmpj;
        if(date == 0)
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if ((map[i][j] == 0 || map[i][j] == 2) && !visited[i][j]) {
                        for (int k = 0; k < 4; k++) {
                            tmpi = i + dx[k];
                            tmpj = j + dy[k];
                            if (tmpi >= 0 && tmpj >= 0 && tmpi < r && tmpj < c) {
                                if (map[tmpi][tmpj] == 1) {
                                    map[tmpi][tmpj] = 0;
                                    nextq.push(make_pair(tmpi, tmpj));
                                    visited[tmpi][tmpj] = true;
                                }
                            }
                        }
                    }
                }
            }
        else {
            while (!nextq.empty()) {
                q.push(nextq.front());
                nextq.pop();
            }
            while (!q.empty()) {
                pair<int, int> tmp = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    tmpi = tmp.first + dx[k];
                    tmpj = tmp.second + dy[k];
                    if (tmpi >= 0 && tmpj >= 0 && tmpi < r && tmpj < c) {
                        if (map[tmpi][tmpj] == 1) {
                            map[tmpi][tmpj] = 0;
                            nextq.push(make_pair(tmpi, tmpj));
                        }
                    }
                }
            }
        }

        //cout << el;
        //for (int i = 0; i < r; i++) {
        //    for (int j = 0; j < c; j++) {
        //        cout << map[i][j];
        //    }
        //    cout << el;
        //}
        date++;
    }
    

    return 0;
}


/*
    Algorithm : BFS

    Time complexity : O(N^2)

*/