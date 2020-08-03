// https://www.acmicpc.net/problem/1260

//시간제한  메모리
//2 초	    128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 1000

using namespace std;

int a[MAX + 1][MAX + 1];
int visited[MAX + 1];
int N, M, start;

queue<int> vq;

void dfs(int vertex) {
    if (visited[vertex] == 1) return;

    cout << vertex << ' ';
    visited[vertex] = 1;

    for (int i = 1; i <= N; i++) {
        if (a[vertex][i] == 1 && visited[i] == 0) {
            dfs(i);
        }       
    }
}

void bfs(int start) {   
    visited[start] = 1;
    vq.push(start);

    while (!vq.empty()) {

        int tmp = vq.front();
        cout << tmp << ' ';

        vq.pop();

        for (int i = 1; i <= N; i++) {
            if (a[tmp][i] == 1 && visited[i] == 0) {
                vq.push(i);
                visited[i] = 1;
            }
        }
    }
}


int main() {
    int tmpi, tmpj;
    cin >> N >> M >> start;

    for (int i = 1; i <= N; i++) 
        for (int j = 1; j <= N; j++) a[i][j] = 0;
    
    for (int i = 1; i <= N; i++) visited[i] = 0;

    for (int j = 1; j <= M; j++) {
        cin >> tmpi >> tmpj;
        a[tmpi][tmpj] = 1;
        a[tmpj][tmpi] = 1;
    }

    dfs(start);
    cout << endl;

    for (int i = 1; i <= N; i++) visited[i] = 0;  // 초기화

    bfs(start);

    return 0;
}


/*
    Algorithm : DFS, BFS

    Time complexity : O(n^2) / O(n^2)

*/