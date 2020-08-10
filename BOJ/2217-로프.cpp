// https://www.acmicpc.net/problem/2217

//시간제한	메모리제한
//2 초	192 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int n;
int r[100001];
int dp[100001];

int main() {
    FAIO;

    int maxx = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }

    sort(r+1, r + n + 1);

    for (int i = 1; i <= n; i++) {
        dp[i] = r[n - i + 1] * i;
        if (maxx < dp[i]) maxx = dp[i];
    }

    cout << maxx;

    return 0;
}


/*
    Algorithm : 
    Time complexity : O(nlogn)

*/