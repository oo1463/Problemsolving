// https://www.acmicpc.net/problem/19542

//시간제한  메모리
//1 초 (추가 시간 없음)	1024 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <list>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, S, D;
bool visited[100001];
queue<int> q;

list<int> l[100001];
int cnt = 0;

int level = 0;

void search(int node) {
    for (auto iter = l[node].begin(); iter != l[node].end(); iter++) {
        if (!visited[*iter]) {
            visited[*iter] = true;
            level++;
            if (level > D) {
                cnt++;
                return;
            }
            search(*iter);
            level--;
        }        
    }
}

int main() {
    FAIO;

    int tmp1, tmp2;
    cin >> N >> S >> D;

    for (int i = 1; i < N; i++) {        
        cin >> tmp1 >> tmp2;
        l[tmp1].push_back(tmp2);
        l[tmp2].push_back(tmp1);
    }

    for (int i = 1; i <= N; i++) {
        visited[S] = true;
        search(S);
        level = 0;
        memset(visited, false, sizeof(visited));
    }
    
    cout << cnt * 2;
    
    return 0;
}


/*
    Algorithm : DFS

    Time complexity : O(N)

*/