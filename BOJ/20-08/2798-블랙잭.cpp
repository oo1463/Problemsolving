// https://www.acmicpc.net/problem/2798

//시간제한  메모리
//1 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int main() {
    FAIO;

    int N, M;
    int card[101];
    int sum, max = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> card[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                sum = card[i] + card[j] + card[k];
                if (sum <= M && sum > max) max = sum;
            }
        }
    }

    cout << max;
    return 0;
}


/*
    Algorithm : array

    Time complexity : O(N^3)

*/