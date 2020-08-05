// https://www.acmicpc.net/problem/1932

//시간제한  메모리
// 2 초	128 MB

#include <iostream>
#include <algorithm>
using namespace std;

int t[501][501];
int sum[501][501];
int N;

int get_max(int a, int b) { return a > b ? a : b; }

int main() {
    
    int maxs = 0;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> t[i][j];
        }
    }

    sum[1][1] = t[1][1];
    sum[2][1] = sum[1][1] + t[2][1];
    sum[2][2] = sum[1][1] + t[2][2];

    for (int i = 3; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            sum[i][j] = t[i][j] + get_max(sum[i - 1][j] , sum[i - 1][j - 1]);
        }
    }

    for (int i = 1; i <= N; i++) {
        maxs = get_max(maxs, sum[N][i]);
    }
        
    cout << maxs;

    return 0;
}


/*
    Algorithm : DP

    Time complexity : O(N^2) , 최악 : N = 500 --> 250000

*/