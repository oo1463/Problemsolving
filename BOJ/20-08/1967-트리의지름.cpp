// https://www.acmicpc.net/problem/1967

//시간제한  메모리
//2 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <list>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

typedef struct noe {
    int node;
    int edge;
}edg;

list<edg> V[10001];
bool visited[10001];
vector<int> distv;
int Ver;
int mx;
int g;

bool desc(int a, int b) { return a > b; }


int dfs(int node, int dist) {
    vector<int> tmpv;

    for (auto i = V[node].begin(); i != V[node].end(); i++) {
        if (!visited[i->node]) {
            visited[i->node] = true;
            g = dfs(i->node, dist) + i->edge;
            tmpv.push_back(g);
        }
    }
    if (!tmpv.empty()) {
        tmpv.push_back(0);
        sort(tmpv.begin(), tmpv.end(), desc);
        if (mx < tmpv[0] + tmpv[1]) mx = tmpv[0] + tmpv[1];
        dist = tmpv[0];
        tmpv.clear();

        return dist;
    }

    return 0;
}


int main() {
    FAIO;

    cin >> Ver;
    for (int i = 0; i < Ver - 1; i++) {
        int t;
        cin >> t;
        int tmp1;
        int tmp2;
        cin >> tmp1 >> tmp2;
        edg tmpe = { tmp1, tmp2 };
        V[t].push_back(tmpe);
    }

    visited[1] = true;
    dfs(1, 0);

    cout << mx;

    return 0;
}


/*
    Algorithm : DFS, tree

    Time complexity : O(N)

*/