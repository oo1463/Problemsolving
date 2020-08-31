// https://www.acmicpc.net/problem/2252

//시간제한  메모리
//2 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, M;
bool visited[32001];
vector<int> v[32001];
stack<int> s;

void dfs(int node) {
    for (auto a : v[node]) {
        if (!visited[a]) {
            visited[a] = true;
            dfs(a);
        }
    }
    s.push(node);
}


int main() {
    FAIO;

    cin >> N >> M;
    while (M--) {
        int x, y;
        cin >> x >> y;

        v[x].push_back(y);
        visited[y] = true;
    }


    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            v[0].push_back(i);
        }
    }

    memset(visited, false, sizeof(visited));
    dfs(0);

    s.pop();

    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }

    return 0;
}


/*
    Algorithm : Topology sort , dfs, stack

    Time complexity : O(N)

*/