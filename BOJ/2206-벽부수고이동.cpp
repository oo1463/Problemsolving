// https://www.acmicpc.net/problem/2206

//시간제한  메모리
//2 초	192 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

typedef struct xy {
    int x;
    int y;
    int destroy;
}xy;

int posx[4] = { 1, 0, -1, 0 };
int posy[4] = { 0, 1 ,0 , -1 };

int maze[1002][1002];
bool visited[2][1002][1002];
int min_count[2][1002][1002];
string arr[1002];
queue<xy> q;
vector<int> v;
int N, M;

int get_min(int a, int b) { return a < b ? a : b; }

void bfs(int x, int y) {

    xy tmp;
    tmp.x = x;
    tmp.y = y;
    tmp.destroy = 0;
    q.push(tmp);
    min_count[0][x][y] = 1;
    visited[tmp.destroy][x][y] = true;

    while (!q.empty()) {
        tmp = q.front();
        q.pop();
        if (tmp.x == N && tmp.y == M) {
            cout << get_min(min_count[0][tmp.x][tmp.y], min_count[1][tmp.x][tmp.y]) << el;
            v.push_back(get_min(min_count[0][tmp.x][tmp.y], min_count[1][tmp.x][tmp.y]));
            return;
        }

        for (int i = 0; i < 4; i++) {
            xy tt;
            tt.x = tmp.x + posx[i];
            tt.y = tmp.y + posy[i];
            tt.destroy = tmp.destroy;
            if (tt.x > 0 && tt.y > 0 && tt.x <= N && tt.y <= M) {
                if (maze[tt.x][tt.y] == 1 && !visited[tt.destroy][tt.x][tt.y] || tt.destroy == 0 && !visited[tt.destroy][tt.x][tt.y]) {
                    if (tt.destroy == 0 && maze[tt.x][tt.y] == 0) tt.destroy = 1;
                    visited[tt.destroy][tt.x][tt.y] = true;
                    q.push(tt);
                    min_count[tt.destroy][tt.x][tt.y] = min_count[tmp.destroy][tmp.x][tmp.y] + 1;                    
                    //cout << tt.x << ' ' << tt.y << ' ' << min_count[tt.x][tt.y]<< endl;
                }
            }            
        }        
    }
}

int main() {    

    cin >> N >> M;

    for (int i = 1; i <= N; i++) cin >> arr[i];

    memset(visited, false, sizeof(visited));
    memset(maze, 0, sizeof(maze));

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == '0') maze[i][j + 1] = 1;
            else maze[i][j + 1] = 0;            
            min_count[0][i][j + 1] = 99999;
            min_count[1][i][j + 1] = 99999;
        }
    }

    bfs(1, 1);
    
    if (v.empty()) cout << "-1" << el;
    
    return 0;
}


/*
    Algorithm : BFS

    Time complexity : O(NM)

*/