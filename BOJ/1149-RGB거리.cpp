// https://www.acmicpc.net/problem/1149

//시간제한  메모리
//0.5 초 (추가 시간 없음)	128 MB

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

int cost[1001][3];
int p[1001][3];
int N;

int get_min(int a, int b) { return a < b ? a : b; }

int main() {
    FAIO;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    for (int i = 0; i < 3; i++) p[1][i] = cost[1][i];


    for (int i = 2; i <= N; i++) {
        p[i][0] = cost[i][0] + get_min(p[i - 1][1], p[i - 1][2]);
        p[i][1] = cost[i][1] + get_min(p[i - 1][0], p[i - 1][2]);
        p[i][2] = cost[i][2] + get_min(p[i - 1][0], p[i - 1][1]);
    }

    int min = get_min(p[N][0], p[N][1]);
    min = get_min(min, p[N][2]);

    cout << min;

    return 0;
}


/*
    Algorithm : DP

    Time complexity : O(N)

*/