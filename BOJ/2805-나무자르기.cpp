// https://www.acmicpc.net/problem/2805

//Time limit	memory limit
  //1 s     	256 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

long long N, M;
long long t[1000001];

int main() {
    FAIO;

    long long maxx = 0;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> t[i];
        if (maxx < t[i]) maxx = t[i];
    }
    
    long long mid;
    long long cnt;
    long long left, right;
    long long answer = 0;
    left = 0;
    right = maxx;
    
    while (left <= right) {
        cnt = 0;

        mid = (left + right) / 2;

        for (int i = 0; i < N; i++) {
            if (t[i] - mid > 0) cnt += t[i] - mid;
        }
        if (cnt >= M) {
            if (answer < mid) answer = mid;
            left = mid + 1;            
        }
        else if (cnt < M) {
            right = mid - 1;
        }
    }
    
    cout << answer;

    return 0;
}


/*
    Algorithm : binary search
    Time complexity : O(NlogN)

*/