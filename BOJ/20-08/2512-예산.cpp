// https://www.acmicpc.net/problem/2512

//시간제한  메모리
//1 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, M;
int acc[10001];

int main() {
    FAIO;
    int max = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> acc[i];
        if (acc[i] > max) max = acc[i];
    }

    cin >> M;

    int left, right, mid;
    int sum, answer = 0;

    left = 0;
    right = max;

    while (left <= right) {
        sum = 0;
        mid = (left + right) / 2;
        for (int i = 0; i < N; i++) {
            if (acc[i] > mid) sum += mid;
            else sum += acc[i];
        }
        if (sum > M) right = mid - 1;
        else {
            if (answer < mid) answer = mid;
            left = mid + 1;
        }
    }

    cout << answer;

    return 0;
}


/*
    Algorithm : binary search

    Time complexity : O(Nlog(max(acc[N])))

*/