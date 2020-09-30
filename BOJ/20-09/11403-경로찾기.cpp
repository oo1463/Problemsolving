// https://www.acmicpc.net/problem/11403

//시간제한  메모리
//1 초	256 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N;
int adj[101][101];
bool visited[101];
bool fl;

void dfs(int node, int j) {    
    if (visited[j]) {
        fl = true;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            visited[i] = true;
            dfs(i,j);
        }
    }

}

int main() {
    FAIO;

    memset(adj, 0, sizeof(adj));
    memset(visited, false, sizeof(visited));

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int tmp;
            cin >> tmp;
            if (tmp == 1) adj[i][j] = 1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            memset(visited, false, sizeof(visited));
            fl = false;
            dfs(i, j);
            if (fl == 1) cout << '1' << ' ';
            else cout << '0' << ' ';
        }
        cout << el;
    }

    return 0;
}


/*
    Algorithm : DFS

    Time complexity : O(N^3)

*/