// https://www.acmicpc.net/problem/11441

//시간제한  메모리
//1 초	256 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, M;
int num[100001];
int sum[100001];

int main() {
    FAIO;

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> num[i];

    sum[0] = 0;
    sum[1] = num[1];
    for (int i = 2; i <= N; i++) sum[i] = sum[i - 1] + num[i];


    cin >> M;

    while (M--) {
        int i, j;
        cin >> i >> j;
        cout << sum[j] - sum[i-1] << el;
    }

    return 0;
}


/*
    Algorithm :

    Time complexity : O(N^2)

*/