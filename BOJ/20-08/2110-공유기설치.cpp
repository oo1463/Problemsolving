// https://www.acmicpc.net/problem/2110

//시간제한  메모리
//2 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int a[200001];
int N;
int C;
int cnt = 0;

int main() {
    FAIO;

    int mid;
    int d = 0;
    int left = 0;
    int right;
    int answer = 0;

    cin >> N >> C;
    for (int i = 0; i < N; i++) cin >> a[i];

    sort(a, a + N);

    right = (a[N - 1] - a[0]) / (C - 1);

    while (left <= right) {
        mid = (left + right) / 2;

        for (int i = 1; i < N; i++) {            
            d += a[i] - a[i - 1];
            if (d < mid) continue;
            else {
                cnt++;
                d = 0;
            }            
        }

        if (cnt >= C - 1) {
            
            left = mid + 1;
            if (answer < mid) answer = mid;
        }
        else {
            right = mid - 1;
        }
        cnt = 0;
        d = 0;
    }
    
    cout << answer;

    return 0;
}


/*
    Algorithm : binary search

    Time complexity : O(NlogN)

*/