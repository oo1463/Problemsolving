// https://www.acmicpc.net/problem/1753

//시간제한  메모리
//1 초	256 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;
typedef struct edg {
    int node;
    int edge;
}edg;

struct cmp {
    bool operator()(edg &a, edg &b) {
        return a.edge > b.edge;
    }
};

int V, E;
queue<int> q;
priority_queue<edg, vector<edg>, cmp> pq[20001];

int dist[20001];

void dijk(int start) {

    for (int i = 1; i <= V; i++) dist[i] = 30000001;
    dist[start] = 0;
    q.push(start);

    while(!q.empty()) {
        int tmp = q.front();
        q.pop();
        
        while (!pq[tmp].empty()) {
            edg i = pq[tmp].top();

            //cout << tmp << '>' << i.node << ' ';
            if (dist[i.node] > dist[tmp] + i.edge) {
                dist[i.node] = dist[tmp] + i.edge;
                q.push(i.node);
            }
            pq[tmp].pop();
        }

    }
    return;
}


int main() {
    FAIO;

    int start;

    cin >> V >> E;
    cin >> start;

    int u, v, w;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        edg tmp = { v,w };
        pq[u].push(tmp);
    }

    //for (int i = 1; i <= V; i++) {
    //    cout << "Node" << i << ' ';
    //    while (!pq[i].empty()) {
    //        edg j = pq[i].top();
    //        cout << '(' << j.node << ' ' << j.edge << ')' << ' ';
    //        pq[i].pop();
    //    }
    //    cout << el;
    //}
        

    dijk(start);

    for (int i = 1; i <= V; i++) {
        if (dist[i] >= 30000001) cout << "INF" << el;
        else cout << dist[i] << el;        
    }

    return 0;
}


/*
    Algorithm : dijkstra

    Time complexity : O(E)

*/