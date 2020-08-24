// https://www.acmicpc.net/problem/11725

//시간제한  메모리
//1 초	256 MB	

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N;
queue<int> q;
int p[100001];
list<int> adj[100001];

void bfs() {
    q.push(1);
    p[1] = -1;

    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        //cout << tmp << ' ' << p[tmp]<< endl;

        for (auto i = adj[tmp].begin(); i != adj[tmp].end(); i++) {
            if (p[*i] == 0) {
                q.push(*i);
                p[*i] = tmp;
            }
        }
    }
}

int main() {
    FAIO;

    cin >> N;

    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs();

    for (int i = 2; i <= N; i++) {
        cout << p[i] << el;
    }

    return 0;
}


/*
    Algorithm : BFS, tree

    Time complexity : O(N)

*/