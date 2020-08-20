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
int in[9];
bool visited[9];

void dfs(int s, int arri) {
    if (arri == M) {
        for (int i = 0; i < arri; i++) cout << arr[i] << ' ';
        cout << el;
        return;
    }

    for (int i = 0; i < N; i++) {

        if (!visited[i]) {
            arr[arri] = in[i];
            visited[i] = true;
            dfs(0, arri + 1);
            visited[i] = false;
        }        
    }
}

int main() {
    FAIO;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> in[i];
    }

    sort(in, in + N);

    dfs(0, 0);

    return 0;
}


/*
    Algorithm : DFS , backtracking

    Time complexity : O(N!/M!))

*/