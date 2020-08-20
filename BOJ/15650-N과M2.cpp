// https://www.acmicpc.net/problem/15650

//시간제한  메모리
//1 초	512 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, M;
int arr[9];

void dfs(int s, int arri) {
    if (arri == M) {
        for (int i = 0; i < arri; i++) cout << arr[i] << ' ';
        cout << el;
        return;
    }

    for (int i = s; i <= N; i++) {
        arr[arri] = i;
        dfs(i + 1, arri + 1);
    }
}

int main() {
    FAIO;

    cin >> N >> M;

    dfs(1, 0);

    return 0;
}


/* 
    Algorithm : DFS , backtracking

    Time complexity : O(N!/((N-M)!*M!))

*/