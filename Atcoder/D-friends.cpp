#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, M;

vector<int> v[200001];
queue<int> q;
bool visited[200001];

int main() {
    FAIO;

    cin >> N >> M;
    while (M--) {
        int ta, tb;
        cin >> ta >> tb;
        v[ta].push_back(tb);
        v[tb].push_back(ta);
    }

    int mx = 0;

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            int cnt = 1;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int tmp = q.front();
                q.pop();

                for (auto a : v[tmp]) {
                    if (!visited[a]) {
                        q.push(a);
                        visited[a] = true;
                        cnt++;
                    }
                }
            }

            if (cnt > mx) mx = cnt;
        }
    }
    cout << mx;
    return 0;
}