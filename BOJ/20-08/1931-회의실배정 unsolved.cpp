// https://www.acmicpc.net/problem/1931

//시간제한  메모리
//2 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int n;
unsigned int h[100001][2];

int main() {
    FAIO;
    int cnt = 0;
    int k;
    vector<int> h1;
    vector<int> h2;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> h[i][0] >> h[i][1];
    }
    k = 0;
    cnt = 1;
    for (int i = 1; i < n; i++) {
        if (h[i][0] >= h[k][1]) {
            k = i;
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}


/*
    Algorithm : Greedy

    Time complexity : O(N)

*/