// https://www.acmicpc.net/problem/3090

//시간제한  메모리
//1 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, T;
int nu[100001];
int n[100001];
int result[100001];

bool diff(int d) {
    memcpy(n, nu, sizeof(n));
       
    int sum = 0;
    for (int i = 0; i < N - 1; i++) {

        if (abs(n[i] - n[i + 1]) > d) {
            if (n[i] > n[i + 1]) {
                sum += n[i] - n[i + 1] - d;
                n[i] = n[i + 1] + d;
            }
            else {
                sum += n[i + 1] - n[i] - d;
                n[i + 1] = n[i] + d;
            }
        }
        //cout << d << ' ' << sum << ' ' << n[i] << ' ' << n[i + 1] << el;

    }
    if (sum > T) return false;
    else return true;
}


int main() {
    FAIO;
    
    cin >> N >> T;
    for (int i = 0; i < N; i++) cin >> nu[i];

    int ans = 1000000000;
    int left = 1, right = 1000000000;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (diff(mid)) {                
            memcpy(result, n, sizeof(result));
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }

    }

    for (int i = 0; i < N; i++) cout << result[i] << ' ';

    return 0;
}


/*
    Algorithm : Binary search

    Time complexity : O(Nlog(10^9))

*/