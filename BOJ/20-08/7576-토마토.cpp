// https://www.acmicpc.net/problem/

//시간제한  메모리
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, M;
int pos[1001][1001];
int day[1001][1001];
int cnt0 = 0;
int cnt = 0;
int save = 0;
queue<pair<int, int>> q;
int posx[4] = { 1, 0, -1, 0 };
int posy[4] = { 0, 1 ,0 , -1 };

void bfs() {

    while (!q.empty()) {
        pair<int, int> tmp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            pair<int, int> tmp2;
            tmp2.first = tmp.first + posx[i];
            tmp2.second = tmp.second + posy[i];
            
            if (tmp2.first > 0 && tmp2.second > 0 && tmp2.first <= N && tmp2.second <= M) {
                if (day[tmp2.first][tmp2.second] == -1 && pos[tmp2.first][tmp2.second] == 0) {
                    //cout <<  tmp2.first << ' ' << tmp2.second << ' ' << pos[tmp2.first][tmp2.second] << el;
                    q.push(tmp2);
                    day[tmp2.first][tmp2.second] = day[tmp.first][tmp.second] + 1;
                    save = day[tmp2.first][tmp2.second];
                    cnt++;
                }
            }
        }
        //cout << cnt0 << ' ' << cnt << el;
        if (cnt == cnt0) {
            cout << save;
            return;
        }
        else if (q.empty()) {
            cout << "-1";
            return;
        }
    }
}

int main() {
    FAIO;

    cin >> M >> N;

    memset(day, -1, sizeof(day));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> pos[i][j];
            if (pos[i][j] == 0) cnt0++;
            else if (pos[i][j] == 1) {
                day[i][j] = 0;
                q.push(pair<int, int>(i, j));
            }                
        }
    }
    bfs();

    return 0;
}

/*
    Algorithm : BFS

    Time complexity : O(NM)

*/