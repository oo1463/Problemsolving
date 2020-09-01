// https://www.acmicpc.net/problem/1043

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

int N, M;
bool infected[51];
int adj[51][51];
int tru;

queue<int> q;

void bfs(int start) {
    q.push(start);

    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        for (int i = 1; i <= N; i++) {
            if (adj[tmp][i] == 1 && !infected[i]) {
                q.push(i);
                infected[i] = true;
            }                    
        }
    }
}

int main() {
    FAIO;

    vector<int> infectv;
    vector<int> party;
    vector<int> v[51];
    int cnt = 0;
    cin >> N >> M;
    cin >> tru;
    while (tru--) {
        int tmp;
        cin >> tmp;
        infected[tmp] = true;
        infectv.push_back(tmp);
    }
    int a = M;

    while (M--) {
        int tmp;        
        cin >> tmp;
        while (tmp--) {
            int partypeople;
            cin >> partypeople;
            v[M+1].push_back(partypeople);

            //cout << el << v[M + 1][0] << el << el;
        }

        for (unsigned int i = 1; i < v[M + 1].size(); i++) {            
            adj[v[M + 1][i]][v[M + 1][i - 1]] = 1;
            adj[v[M + 1][i - 1]][v[M + 1][i]] = 1;
        }
    }

    for (unsigned int i = 0; i < infectv.size(); i++) bfs(infectv[i]);

    for (int i = 1; i <= a; i++) if (!infected[v[i][0]]) cnt++;

    cout << cnt;

    return 0;
}


/* 
    Algorithm : BFS

    Time complexity : O(N^2 + NM)

*/