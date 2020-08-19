// https://www.acmicpc.net/problem/14502

//시간제한  메모리
//2 초	512 MB //

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

typedef struct p {
    int x;
    int y;
}pos;

int map[9][9];
int tmpmap[9][9];
int tmpmap2[9][9];
int N, M;
vector<pos> v;
bool visited1[9][9];

queue<pos> q;
int maxcnt;
int cnt;

int dx[4] = { 0, 0 , 1, -1 };
int dy[4] = { 1, -1 , 0, 0 };

void bfs() {
    for (int i = 0; i < v.size(); i++) {
        pos tmpp = v[i];
        q.push(tmpp);
    }

    while (!q.empty()) {
        pos tmpp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tmpx = tmpp.x + dx[i];
            int tmpy = tmpp.y + dy[i];
            pos tt = { tmpx, tmpy };
            if (tmpx > 0 && tmpy > 0 && tmpx <= N && tmpy <= M && tmpmap[tmpx][tmpy] == 0) {
                tmpmap[tmpx][tmpy] = 2;
                q.push(tt);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (tmpmap[i][j] == 0) cnt++;
        }
    }
}

void dfs(int arri) {
    if (arri == 3) {
        cnt = 0;
        memcpy(tmpmap2, tmpmap, sizeof(tmpmap2));
        bfs();
        memcpy(tmpmap, tmpmap2, sizeof(tmpmap));
        if (maxcnt < cnt) maxcnt = cnt;
        return;
    }

    for(int i=1;i<=N; i++)
        for (int j = 1; j <= M; j++) {
            if (tmpmap[i][j] == 0) {
                tmpmap[i][j] = 1;
                dfs(arri + 1);
                tmpmap[i][j] = 0;
            }
        }
}

int main() {
    FAIO;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];     
            pos tmp = { i,j };
            if (map[i][j] == 2) v.push_back(tmp);
        }
    }
    memcpy(tmpmap, map, sizeof(tmpmap));

    dfs(0);
    cout << maxcnt;

    return 0;
}


/*
    Algorithm : DFS, BFS

    Time complexity : O((NM)^2 * (NM)^3)

*/