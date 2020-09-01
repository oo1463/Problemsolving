// https://www.acmicpc.net/problem/1806

//시간제한  메모리
//1 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, S;
int num[100001];

int main() {
    FAIO;

    cin >> N >> S;
    for (int i = 0; i < N; i++) cin >> num[i];
    int t;
    int sum = 0;

    int left, right, mid;    
    int answer = N + 1;
    left = 1;
    right = N + 1;

    while (left <= right) {
        sum = 0;
        int mx;
        mid = (left + right) / 2;

        for (int i = 0; i < mid; i++) sum += num[i];        
        mx = sum;
        for (int i = 1; i + mid <= N; i++) {
            sum = sum - num[i - 1] + num[i + mid - 1];
            if (mx < sum) mx = sum;
        }
        if (mx < S) {
            left = mid + 1;
        }
        else {
            if (answer > mid) answer = mid;
            right = mid - 1;
        }
        cout << mid << el;
    }
    if (answer == N + 1) cout << '0';
    else cout << answer;

    return 0;
}


/*
    Algorithm : Binary Search

    Time complexity : O(NlogN)

*/