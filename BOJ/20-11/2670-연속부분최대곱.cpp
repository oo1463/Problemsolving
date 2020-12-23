// https://www.acmicpc.net/problem/2670

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N;
bool dp[1001];

int main() {
    FAIO;

    cin >> N;

    dp[1] = true;
    dp[2] = false;
    dp[3] = true;
    dp[4] = true;
   
    for (int i = 5; i <= N; i++) if (dp[i-1] == false || dp[i - 3] == false || dp[i - 4] == false) dp[i] = true;
    for (int i = 1; i <= N; i++) cout << dp[i] << ' ';

    if (dp[N] == true) cout << "SK";
    else cout << "CY";

    return 0;
}


/*
    Algorithm :
    Time complexity : O(N^2)

*/