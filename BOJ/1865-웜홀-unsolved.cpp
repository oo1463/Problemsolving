// https://www.acmicpc.net/problem/1865

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

bool visited[501];
int dist[501];
queue<int> q;
int adj[501][501];
int N;

bool bfs(int start) {
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int tmp = q.front();
        q.pop();

        for (int i = 1; i <= N; i++) {

            if (adj[tmp][i] != 0 && !visited[i]) {
                
                visited[i] = true;
                q.push(i);
                dist[i] = dist[tmp] + adj[tmp][i];
            }
            else if (adj[tmp][i] != 0 && visited[i]) {
                if (dist[tmp] + adj[tmp][i] < dist[i]) dist[i] = dist[tmp] + adj[tmp][i];
                if (i == start && dist[i] < 0) {
                    return true;
                }
            }
        }
    }
    //cout << el;
    //cout << dist[start] << el;


    //cout << dist[start] << " fuck" << el;

    return false;
}

int main() {
    FAIO;

    int T;
    cin >> T;

    while (T--) {
        memset(adj, 0, sizeof(adj));


        int M, W;
        int S, E, T;
        int flag = 0;
        cin >> N >> M >> W;
        while (M--) {
            cin >> S >> E >> T;
            adj[S][E] = T;
            adj[E][S] = T;
        }
        while (W--) {
            cin >> S >> E >> T;
            adj[S][E] = -T;
        }

        for (int i = 1; i <= N; i++) {
            for (int i = 1; i <= N; i++) {
                dist[i] = 0;
                visited[i] = false;
            }

            if (bfs(i)) {
                cout << "YES" << el;
                flag = 1;
                break;
            }
        }
            

        if(flag == 0) cout << "NO" << el;
    }
    

    return 0;
}


/*
    Algorithm : BFS,그래프 최단거리 , 벨만포드

    Time complexity : O(N^2)

*/