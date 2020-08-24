// https://www.acmicpc.net/problem/13549

//시간제한  메모리
//2 초	512 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

queue<int> q;
int cnt[100002];
bool visited[100002];
int N, K;

void bfs() {
    q.push(N);
    visited[N] = true;

    while (!q.empty()) {
        int tmp = q.front();
        q.pop();

        int num = tmp;

        while (num <= 100000 && num >= 0) {
            if (num*2 <= 100000 && !visited[num*2]) {
                cnt[num*2] = cnt[tmp];
                visited[num*2] = true;
            }

            if (num - 1 >= 0 && !visited[num - 1]) {
                visited[num - 1] = true;
                q.push(num - 1);
                cnt[num - 1] = cnt[tmp] + 1;
            }
            if (num + 1 <= 100000 && !visited[num + 1]) {
                visited[num + 1] = true;
                q.push(num + 1);
                cnt[num + 1] = cnt[tmp] + 1;
            }

            if (num * 2 == K || num + 1 == K || num - 1 == K) {
                cout << cnt[K];
                exit(0);
            }
            num *= 2;

            if (num == 0) break;

        }
    }

}

int main() {
    FAIO;

    cin >> N >> K;

    bfs();

    
    return 0;
}


/*
    Algorithm : BFS

    Time complexity : O(logN)

*/