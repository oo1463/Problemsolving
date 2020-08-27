// https://www.acmicpc.net/problem/1005

//시간제한  메모리
//1 초	512 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N;
int t[1001];
int ttt[1001];
int adj[1001][1001];
vector<int> v[1001];
queue<int> q;

int bfs(int start) {
    q.push(start);
    ttt[start] = t[start];
    int mx = t[start];
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        
        /*for (int i = 1; i <= N; i++) {
            if (adj[tmp][i] == 1) {
                if (ttt[i] < ttt[tmp] + t[i]) {
                    ttt[i] = ttt[tmp] + t[i];
                    q.push(i);
                    if (ttt[i] > mx) mx = ttt[i];
                }
            }
        }*/

        for (auto a = v[tmp].begin(); a != v[tmp].end(); a++) {
            if (ttt[*a] < ttt[tmp] + t[*a]) {
                ttt[*a] = ttt[tmp] + t[*a];
                q.push(*a);
                if (ttt[*a] > mx) mx = ttt[*a];
            }
        }

    }
    return mx;
}

int main() {
    FAIO;

    int T;    
    int K,W;
    cin >> T;
    while (T--) {
        memset(ttt, 0, sizeof(ttt));
        memset(t, 0, sizeof(t));
        //memset(adj, 0, sizeof(adj));
        for (int i = 0; i <= N; i++) v[i].clear();
        
        cin >> N >> K;
        for (int i = 1; i <= N; i++) cin >> t[i];
        for (int i = 1; i <= K; i++) {
            int x, y;
            cin >> x >> y;
            v[y].push_back(x);
            //adj[y][x] = 1;
        }

        cin >> W;
        cout << bfs(W) << el;
    }

    return 0;
}


/*
    Algorithm : BFS, topology sort

    Time complexity : O(N^2)

*/