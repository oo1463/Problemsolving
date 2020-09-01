// https://www.acmicpc.net/problem/1912

//시간제한  메모리
//1 초 (추가 시간 없음)	128 MB

#include <iostream>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int a[100001];
int dp[100001];

int get_max(int a, int b) { return a > b ? a : b; }

int main() {
    FAIO;

    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];        
    }

    
    dp[0] = a[0];
    int max = dp[0];

    for (int i = 1; i < n; i++) {
        dp[i] = get_max(dp[i - 1] + a[i], a[i]);
        max = get_max(max, dp[i]);
    }

    cout << max;

    return 0;
}


/*
    Algorithm : DP

    Time complexity : O(N)

*/