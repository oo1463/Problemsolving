// https://www.acmicpc.net/problem/1826

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

int N, L, P;
priority_queue<int, vector<int>, less<int> > pq;
pair<int, int> gs[10001];

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    FAIO;

    int tmpj = -1;
    int cnt = 0;
    int sum = 0;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> gs[i].first >> gs[i].second;
    cin >> L >> P;

    sort(gs, gs + N, cmp);

    for (int i = 0; i < N; i++) {
        if (P + sum < gs[i].first) {
            cout << "-1";
            return 0;
        }
        sum += gs[i].second;
        if (i == N - 1 && P + sum < L) {
            cout << "-1";
            return 0;
        }
    }
    
    pq.push(0);
    for (int i = 0; i < N; i++) {
        if (gs[i].first <= P) pq.push(gs[i].second);
        else {
            cnt++;
            P = P + pq.top();
            pq.pop();
            i--;
        }

        if (P >= L) {
            cout << cnt;
            return 0;
        }
    }

    while (P < L) {
        //if (pq.empty()) {
        //    cout << "-1";
        //    return 0;
        //}
        P += pq.top();
        pq.pop();
        cnt++;
    }

    cout << cnt;

    return 0;
}


/*
    Algorithm : Greedy, Heap

    Time complexity : O(N)

*/