#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

typedef struct a {
    int d;
    int h;
    int q_number;
    bool deka;
}people;

struct cmp {
    bool operator()(people a, people b) {
        if (a.d == b.d) {
            if (a.h == b.h) return a.q_number > b.q_number;
            return a.h < b.h;
        }
        return a.d < b.d;
    }
};

int N, M, K;
people p[100001];
queue<people> q[100001];
priority_queue<people,vector<people> , cmp > pq;

int main() {
    FAIO;

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        cin >> p[i].d >> p[i].h;
        p[i].deka = false;
        if(i == K+1) p[i].deka = true;
        p[i].q_number = (i - 1) % M + 1;        
        q[p[i].q_number].push(p[i]);
    }

    for (int i = 1; i <= M; i++) {
        people tmp;
        if (!q[i].empty()) {
            tmp = q[i].front();
            q[i].pop();
            pq.push(tmp);
        }
    }

    for (int i = 1; i <= N; i++) {
        people tp = pq.top();
        //cout << tp.d << ' ' << tp.h << ' ' << tp.deka << el;

        if (tp.deka) {
            cout << i - 1;
            break;
        }

        pq.pop();
        //cout << pq.top().d << ' ' << pq.top().h << ' ' << pq.top().deka << el;

        people next; 
        if (!q[tp.q_number].empty()) {
            next = q[tp.q_number].front();
            q[tp.q_number].pop();
            pq.push(next);
        }
        
    }
   
    return 0;
}
