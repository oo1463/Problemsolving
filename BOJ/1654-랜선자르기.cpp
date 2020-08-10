// https://www.acmicpc.net/problem/1654

//시간제한  메모리
//2 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, K;
long long len[10001];
int main() {
    FAIO;

    long long left, right, mid;
    long long qsum;
    long long max = 0;
    long long answer = 0;
    cin >> K >> N;

    for (int i = 0; i < K; i++) {
        cin >> len[i];
        if (len[i] > max) max = len[i];
    }

    left = 1;
    right = max;

    while (left <= right) {
        qsum = 0;
        mid = (left + right) / 2;
        for (int i = 0; i < K; i++) qsum += len[i] / mid;

        if (qsum >= N) {
            if (answer < mid) answer = mid;

            left = mid + 1;
        }
        else if (qsum < N) right = mid - 1;
    }

    cout << answer;

    

    return 0;
}


/*
    Algorithm : binary search

    Time complexity : O(Klog(maxk))

*/