// https://www.acmicpc.net/problem/2585

//시간제한  메모리
//1 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <math.h>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

typedef struct a {
    int x;
    int y;
    int cnt;
}position;

position pos[1002];
int N, K;

bool bfs(int oil) {
    bool visited[1002];
    memset(visited, false, sizeof(visited));
    for (int i = 0; i <= N + 1; i++) pos[i].cnt = 0;
    queue<position> q;

    pos[0].cnt = 0;
    q.push(pos[0]);
    visited[0] = true;
    
    while (!q.empty()) {
        position tmp = q.front();
        q.pop();        
        if (tmp.cnt > K) continue;

        for (int i = 1; i <= N+1 ; i++) {
            double dist = sqrt(pow(pos[i].x - tmp.x, 2) + pow(pos[i].y - tmp.y, 2));
            if (!visited[i] && dist <= oil * 10) {                
                pos[i].cnt = tmp.cnt + 1;
                visited[i] = true;
                q.push(pos[i]);
                //cout << oil <<" 가능함" << pos[i].x << ' ' << pos[i].y << "   "<< tmp.x << ' ' << tmp.y << "거리는 :"<< dist << "cnt :" << pos[i].cnt << el;
            }
        }
        if (pos[N + 1].cnt <= K + 1 && pos[N + 1].cnt > 0) return true;
    }

    return false;
}

int main() {
    FAIO;

    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> pos[i].x >> pos[i].y;
    pos[0].x = 0;
    pos[0].y = 0;

    pos[N+1].x = 10000;
    pos[N+1].y = 10000;

    int ans = 1414;
    int l = 1, r = 1414;
    int m;
    while (l <= r)
    {
        m = (l + r) / 2;
        bool to = bfs(m);
        if (!to) {
            l = m + 1;
        }
        else {
            if (ans > m)
                ans = m;
            r = m - 1;
        }
    }

    cout << ans;

    return 0;
}


/*
    Algorithm : BFS, binary search

    Time complexity : O(NlonN)

*/