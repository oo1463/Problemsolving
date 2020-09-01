// https://www.acmicpc.net/problem/2579

//시간제한  메모리
//1 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sum[301];
int score[301];
int N;

int get_max(int a, int b) { return a > b ? a : b; }

int main() {

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> score[i];
    }

    score[0] = 0;
    sum[0] = score[0];
    sum[1] = score[1];

    sum[2] = score[2] + sum[1];
    sum[3] = get_max(score[3] + sum[1], score[3] + score[2]);
    for (int i = 3; i <= N; i++) {
        sum[i] = get_max(score[i] + sum[i - 2], score[i] + sum[i - 3] + score[i - 1]);
    }

    cout << sum[N];

    return 0;
}


/*
    Algorithm : DP

    Time complexity : O(N)

*/