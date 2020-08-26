// https://www.acmicpc.net/problem/1516

//시간제한  메모리
//2 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N;
int t[501];
int ttt[501];
int adj[501][501];
queue<int> q;
bool visited[501];

void bfs() {
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        //cout << tmp << el;

        for (int i = 1; i <= N; i++) {
            if (!visited[i] && adj[tmp][i] == 1) {
                ttt[i] = ttt[tmp] + t[i];
                visited[i] = true;
                q.push(i);
            }
            if (visited[i] && adj[tmp][i] == 1) {
                if (ttt[i] < ttt[tmp] + t[i]) {
                    ttt[i] = ttt[tmp] + t[i];
                    q.push(i);
                }
            }
        }
    }
}

int main() {
    FAIO;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> t[i];
        for(int j = 1; j<=N; j++) {
            int tmp;
            cin >> tmp;
            if (tmp == -1) {
                if (j == 1) adj[0][i] = 1;
                break;
            }
            else adj[tmp][i] = 1;            
        }
    }

    //for (int i = 1; i <= N; i++) {
    //    for (int j = 1; j <= N; j++) {
    //        cout << adj[i][j] << ' ';
    //    }
    //    cout << el;
    //}

    bfs();

    for (int i = 1; i <= N; i++) cout << ttt[i] <<el;

    return 0;
}


/*
    Algorithm : BFS

    Time complexity : O(N^3)

*/