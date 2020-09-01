// https://www.acmicpc.net/problem/13305

//시간제한  메모리
//2 초	512 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N;
long long gs[100001];
long long r[100000];
long long sum= 0, mn = 0;

void solve() {
    for (int i = 1; i <= N;) {
        for (int j = i + 1; j <= N; j++) {
            sum += r[j - 1];
            if (gs[i] <= gs[j]) {
                if (j >= N) {
                    mn += sum * gs[i];
                    return;
                }
                continue;
            }
            else {
                mn += sum * gs[i]; 
                if (j >= N) return;
                i = j;
                break;
            }
        }
        sum = 0;
    }
}

long long dp[100001];

void solve2() {
    long long minn = gs[1];
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + minn * r[i - 1];
        if (minn > gs[i]) minn = gs[i];
    }
}

int main() {
    FAIO;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> r[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> gs[i];
    }

    solve2();

    cout << dp[N];

    return 0;
}


/*
    Algorithm : Greedy , DP

    Time complexity : O(N)

*/