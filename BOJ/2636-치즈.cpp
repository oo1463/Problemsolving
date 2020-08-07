// https://www.acmicpc.net/problem/2636

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

int n, m;
int square[101][101];
int our[101][101];
bool visited[101][101];
queue<pair<int,int>> q;

int dx[4] = { 1 , 0 ,-1 ,0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(){
    pair<int, int> tmp = pair<int, int>(1, 1);
    q.push(tmp);
    visited[tmp.first][tmp.second] = true;

    while (!q.empty()) {        

        tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = tmp.first + dx[i];
            int y = tmp.second + dy[i];
            if (x > 0 && y > 0 && x <= n && y <= m && !visited[x][y] ) {
                if (square[x][y] == 0) {                    
                    q.push(pair<int, int>(x, y));
                    visited[x][y] = true;
                }
                if (square[x][y] == 1) {
                    visited[x][y] = true;
                    our[x][y] = 0;
                }
            }
        }
    }    
}


int main() {
    FAIO;
    int cnt1, cnt2;    

    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> square[i][j];
            our[i][j] = square[i][j];
        }
    }

    for (int k = 1; k <= 100; k++) {
        memset(visited, false, sizeof(visited));

        cnt1 = 0;
        cnt2 = 0;
        bfs();
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (square[i][j] != 0) cnt1++;

                square[i][j] = our[i][j];
                if (square[i][j] != 0) cnt2++;

            }
        }

        /*for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << square[i][j] << ' ';
            }
            cout << el;
        }
        cout << el;*/

        if (cnt2 == 0) {
            cout << k << el;
            cout << cnt1;
            
            return 0;
        }

    }

    return 0;
}


/*
    Algorithm : BFS

    Time complexity : O(N^3)

*/