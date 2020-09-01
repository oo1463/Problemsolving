// https://www.acmicpc.net/problem/2056

//시간제한  메모리
//2 초	256 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N;
int t[10001];
int ttt[10001];
int adj[501][501];
vector<int> v[10001];
queue<int> q;

void bfs() {
    q.push(0);

    while (!q.empty()) {
        int tmp = q.front();
        q.pop();

        for (auto a = v[tmp].begin(); a != v[tmp].end(); a++) {
            if (ttt[*a] < ttt[tmp] + t[*a]) {
                ttt[*a] = ttt[tmp] + t[*a];
                q.push(*a);
            }
        }
    }
}

int main() {
    FAIO;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> t[i];
        int num;
        cin >> num;
        if (num == 0) v[0].push_back(i);
        else while (num--) {
            int tmp;
            cin >> tmp;
            v[tmp].push_back(i);            
        }
    }

    bfs();
    int mx = 0;
    for (int i = 1; i <= N; i++) if (mx < ttt[i]) mx = ttt[i];
    
    cout << mx;
    return 0;
}


/*
    Algorithm : BFS

    Time complexity : O(N*100)

*/