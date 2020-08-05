// https://www.acmicpc.net/problem/1463

//시간제한  메모리
//2 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
queue<int> q;
int d[1000001];

void bfs(int x) {
    q.push(x);
    int tmp;

    while (!q.empty()) {
        tmp = q.front();        
        q.pop();        

        //cout << tmp << ' ' << d[tmp] << endl;
        if (tmp == N) {
            cout << d[tmp];
            return;
        }

        if(3 * tmp <= N)
            if (d[3 * tmp] == -1) {
                q.push(3 * tmp);
                d[3 * tmp] = d[tmp] + 1;                                
            }

        if (2 * tmp <= N)
            if (d[2 * tmp] == -1) {
                q.push(2 * tmp);
                d[2 * tmp] = d[tmp] + 1;                
            }

        if (tmp + 1 <= N)
            if (d[1 + tmp] == -1) {
                q.push(1 + tmp);
                d[1 + tmp] = d[tmp] + 1;                
            }
        
    }

}

int main() {

    cin >> N;
    for (int i = 2; i <= N; i++) d[i] = -1;    
    d[1] = 0;

    bfs(1);

    return 0;
}


/*
    Algorithm : BFS , DP (bottom up)

    Time complexity : O(N)

*/