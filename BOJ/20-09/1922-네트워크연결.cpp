// https://www.acmicpc.net/problem/1922

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, M;
int root[1001];
vector<pair<pair<int, int>, int> > v;

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.second < b.second;
}

int find(int node) {
    if (root[node] == node) return node;
    else return root[node] = find(root[node]);
}

void unio(int x, int y) {
    x = find(x);
    y = find(y);

    root[y] = x;
}


int main() {
    FAIO;

    cin >> N >> M;
    for (int i = 0; i < N; i++) root[i] = i;

    while (M--) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(make_pair(make_pair(a, b), c));
    }

    sort(v.begin(), v.end(), cmp);
    int sum = 0;
    for (auto a : v) {
        if (find(a.first.first) != find(a.first.second)) {
            unio(a.first.first, a.first.second);
            sum += a.second;
        }
    }
    
    cout << sum;

    return 0;
}


/*
    Algorithm :

    Time complexity : O(N^2)

*/