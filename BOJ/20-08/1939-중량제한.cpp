// https://www.acmicpc.net/problem/1939

//시간제한  메모리
//1 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <list>

#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

typedef struct a {
    int node;
    int edge;
}info;

list<info> l[10001];
int N, M, st, la;

bool bfs(int weight) {
    bool mx[10001] = { false };
    queue<int> q;

    q.push(st);
    mx[st] = true;

    while (!q.empty()) {
        int tmp = q.front();
        q.pop();

        if (mx[la]) return true;
        for (auto i = l[tmp].begin(); i != l[tmp].end(); i++) {
            //cout << tmp << "->" << i->node << " 간선 : " << i->edge << "   " << mx[tmp] << ' ' << mx[i->node] << el;
            if (!mx[i->node] && i->edge >= weight) { // not visited
                q.push(i->node);
                mx[i->node] = true;
            }
        }
    }

    return false;
}


int main() {
    FAIO;

    int t1, t2, c;
    info tmp;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> t1 >> t2 >> c;
        tmp.node = t2;
        tmp.edge = c;
        l[t1].push_back(tmp);
        tmp.node = t1;        
        l[t2].push_back(tmp);
    }

    cin >> st >> la;

    int ans = 0;
    int l = 1, r = 1000000000;
    int m;
    while (l <= r)
    {

        m = (l + r) / 2;
        bool to = bfs(m);
        if (to) {
            if (ans < m)
                ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    
    cout << ans;

    return 0;
}


/*
    Algorithm : BFS , binarysearch

    Time complexity : O(N + E)

*/