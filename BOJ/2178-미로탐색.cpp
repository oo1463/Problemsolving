// https://www.acmicpc.net/problem/2178

//시간제한  메모리
// 1 초	    192 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int maze[102][102];
bool visited[102][102];
int min_count[102][102];
string arr[102];
queue<pair<int, int>> q;

int level = 0;

int posx[4] = { 1, 0, -1, 0 };
int posy[4] = { 0, 1 ,0 , -1 };

int N, M;

void bfs(int x, int y) {

    q.push(pair<int, int>(x, y));
    pair<int, int> tmp;
    min_count[x][y] = 1;
    visited[x][y] = true;

    while (!q.empty()) {
        tmp = q.front();
        q.pop();        

        for (int i = 0; i < 4; i++) {
            int tmpx = tmp.first + posx[i];
            int tmpy = tmp.second + posy[i];

            if (maze[tmpx][tmpy] == 1 && !visited[tmpx][tmpy]) {
                visited[tmpx][tmpy] = true;

                q.push(pair<int, int>(tmpx, tmpy));
                min_count[tmpx][tmpy] = min_count[tmp.first][tmp.second] + 1;      
                if (tmpx == N && tmpy == M) {
                    cout << min_count[tmpx][tmpy];
                    return;
                }
                //cout << tmpx << ' ' << tmpy << ' ' << min_count[tmpx][tmpy]<< endl;
            }
        }

    }
}



int main() {
    
    cin >> N >> M;

    for (int i = 1; i <= N; i++) cin >> arr[i];

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == '1') maze[i][j + 1] = 1;
            else maze[i][j + 1] = 0;
            visited[i][j + 1] = false;
            min_count[i][j+1] = 0;
        }
    }
    bfs(1, 1);    

    return 0;
}


/*
    Algorithm : BFS

    Time complexity : O(NM)

*/