// https://www.acmicpc.net/problem/11053

//시간제한  메모리
//1 초	256 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
;
using namespace std;

int n;
int a[1001];
int dp[1001];


int main() {
    FAIO;
        
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    a[0] = 0;
    dp[0] = 0;
    dp[1] = 1;
    int max;
    int ab = 0;

    for (int i = 1; i <= n; i++) {
        max = 0;
        for (int j = 1; j <= i - 1; j++) {
            if (a[j] < a[i]) {
                if (max < dp[j]) max = dp[j];
            }
        }
        dp[i] = max + 1;
        if (ab < dp[i]) ab = dp[i];
    }



    cout << ab;

    return 0;
}


/*
    Algorithm : DP

    Time complexity : O(N^2)

*/