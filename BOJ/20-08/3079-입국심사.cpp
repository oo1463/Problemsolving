// https://www.acmicpc.net/problem/3079

//시간제한  메모리
//1 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

long long N, M;
long long t[100001];

int main() {
    FAIO;

    long long mx = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> t[i];
        if (mx < t[i]) mx = t[i];
    }

    long long ans = LLONG_MAX;
    long long left = 1, right = mx * M;
    while (left <= right) {
        long long comp = 0;
        long long mid = (left + right) / 2;
        for (int i = 0; i < N; i++) comp += mid / t[i];

        if (comp >= M) {
            if (ans > mid) ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
        //cout << mid << "초 , " << comp << ' ' << ans << el;

    }

    cout << ans;

    return 0;
}


/*
    Algorithm : binary search

    Time complexity : O(Nlog10^9)

*/