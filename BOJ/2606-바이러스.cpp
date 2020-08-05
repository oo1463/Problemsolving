// https://www.acmicpc.net/problem/2606

//시간제한  메모리
//1 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int mat[101][101];
bool visited[101];
int cnt = 0;

void dfs(int vertex) {
    visited[vertex] = true;

    for (int i = 1; i <= N; i++) {
        if (mat[vertex][i] == 1 && !visited[i]) {
            cnt++;
            dfs(i);
        }
    }
}

int main() {

    int x, y;
    cin >> N;
    cin >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            mat[i][j] = 0;
        }
        visited[i] = false;
    }


    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        mat[x][y] = 1;
        mat[y][x] = 1;
    }

    dfs(1);
    cout << cnt;

    return 0;
}


/*
    Algorithm : DFS

    Time complexity : O(N^2)

*/