// https://www.acmicpc.net/problem/5567

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int n, m;
bool adj[501][501];
int cnt;
bool visited[501];
queue<pair<int, int> > q;

void bfs(int start){
    
    visited[start] = true;
    q.push({start, 0});

    while(!q.empty()){        
        pair<int, int> tmp = q.front();
        q.pop();
        if(tmp.second > 1) break;

        for(int i=1; i<=n; i++){
            if(adj[tmp.first][i] && !visited[i]){
                q.push({i, tmp.second + 1});
                visited[i] = true;
                cnt++;
            }
        }
        
    }

}

int main() {
    FAIO;

    cin >> n >> m;

    while(m--){
        int a,b;
        cin >> a >> b;
        adj[a][b] = true;
        adj[b][a] = true;
    }

    bfs(1);
    cout << cnt;


    return 0;
}


/*
    Algorithm : bfs

    Time complexity : O(N^2)
    
*/