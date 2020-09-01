// https://www.acmicpc.net/problem/14501

//시간제한  메모리
//2 초	512 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int get_max(int a, int b) { return a > b ? a : b; }
int N;
int t[16];
int p[16];
int sum = 0;
int maxx = 0;
int dp[16];

void dfs(int day) {
    if (day > N || t[day] + day > N + 1) {
        return;
    }
    sum += p[day];
    if (maxx < sum) maxx = sum;
    for (int i = day + t[day]; i <= N; i++) {
        dfs(i);
    }
    sum -= p[day];

}

int main() {
    FAIO;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> t[i] >> p[i];
    }
    for (int i = 1; i <= N; i++) {
        //dfs(i);

        if (i + t[i] <= N + 1) // i번째 날에 일을 한 경우
            dp[i + t[i]] = get_max(dp[i + t[i]], dp[i] + p[i]);

        dp[i + 1] = get_max(dp[i + 1], dp[i]); // i번째 날에 일을 하지 않은 경우
    }

    cout << dp[N+1];

    return 0;
}


/*
    Algorithm : Backtracking

    Time complexity : O(N!)

*/