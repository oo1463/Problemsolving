// https://www.acmicpc.net/problem/2293

//시간제한  메모리
//0.5 초 (추가 시간 없음)	4 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int n, k;
int c[101];
int sum = 0;
int cnt = 0;




int main() {
    FAIO;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }


    cout << cnt;

    return 0;
}


/*
    Algorithm : DP

    Time complexity : O(N^2)

*/