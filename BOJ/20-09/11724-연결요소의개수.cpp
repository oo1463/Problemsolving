// https://www.acmicpc.net/problem/11724

//시간제한  메모리
//3 초	256 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, M;
bool edge[1001][1001];
queue<int> q;
bool visited[1001];
int cnt = 0;

void bfs(int node) {    
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int tmp = q.front();
        q.pop();

        for (int i = 1; i <= N; i++) {
            if (edge[tmp][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    cnt++;
}

int main() {
    FAIO;

    memset(edge, false, sizeof(edge));
    memset(visited, false, sizeof(visited));

    cin >> N >> M;
    while (M--) {
        int u, v;
        cin >> u >> v;
        edge[u][v] = true;
        edge[v][u] = true;
    }

    for (int i = 1; i <= N; i++) if (!visited[i]) bfs(i);
     
    cout << cnt;

    return 0;
}


/*
    Algorithm : BFS

    Time complexity : O(N^2)

*/