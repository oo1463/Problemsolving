// https://www.acmicpc.net/problem/1202

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

typedef struct a {
    long long m;
    long long v;
}jew;

int N, K;

jew jews[300001];
long long c[300001];
long long sum = 0;

priority_queue<long long, vector<long long> , less<long long > > pq;

bool cmp(jew a, jew b) {
    return a.m < b.m;
}

int main() {
    FAIO;
    int tmp = 1;

    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> jews[i].m >> jews[i].v;
    for (int i = 1; i <= K; i++) cin >> c[i];

    sort(jews + 1, jews + N + 1, cmp);
    sort(c + 1, c + K + 1);
  
    for (int i = 1; i <= K; i++) {        
        for (int j = tmp; j <= N && jews[j].m <= c[i]; j++) {
            pq.push(jews[j].v);
            tmp = j + 1;
        }
            
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }        
    }

    cout << sum;

    return 0;
}


/*
    Algorithm : sort, heap

    Time complexity : O(KlogK)

*/