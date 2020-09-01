// https://www.acmicpc.net/problem/14503

//시간제한  메모리
//2 초	512 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, M;
int map[51][51];
int dx[4] = {0, -1, 0, 1};
int dy[4] = { -1, 0, 1, 0 };
int cnt= 0;

void dfs(int arri, int now, int x, int y) {

    map[x][y] = 2;

    int i, j = 0;

    for (i = now ; j < 4; i = (i + 3) % 4, j++) {
        int tmpx = x + dx[i];
        int tmpy = y + dy[i];
        if (tmpx < 1 || tmpy < 1 || tmpx > N || tmpy > M) continue;

        if (map[tmpx][tmpy] == 0) {
            //cout << tmpx << ' ' << tmpy << el;

            dfs(arri + 1, (i + 3) % 4, tmpx, tmpy);
        }
        
        if (j == 3) {
            i = (i + 3) % 4;
            //cout << tmpx << ' ' << tmpy << "   " << i << ' ' << now << el;
            if (map[x + dx[(now + 3) % 4]][y + dy[(now + 3) % 4]] == 1) {
                for (int k = 1; k <= N; k++) {
                    for (int l = 1; l <= M; l++) {
                        if (map[k][l] == 2) cnt++;
                    }                    
                }
                cout << cnt;
                exit(0);
            }
            else dfs(arri, now, x+dx[(now+3)%4], y + dy[(now+3)%4]);
        }
    }        
}

int main() {
    FAIO;

    cin >> N >> M;

    int now, r, c;
    cin >> r >> c >> now;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }

    dfs(0, now, r+1, c+1);
    return 0;
}


/*
    Algorithm :

    Time complexity : O(N^2)

*/