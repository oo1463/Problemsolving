// https://www.acmicpc.net/problem/

//시간제한  메모리
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <math.h>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N;
int s[100001];

bool cmp(int a, int b) { return abs(a) < abs(b); }
int main() {
    FAIO;

    int min = 2000001;
    int tmpi = 0;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> s[i];

    sort(s, s + N, cmp);

    for (int i = 0; i < N - 1; i++) {
        if (abs(s[i] + s[i + 1]) < min) {
            min = abs(s[i] + s[i + 1]);
            tmpi = i;
        }
    }
    if(s[tmpi] > s[tmpi+1]) cout << s[tmpi + 1] << ' ' << s[tmpi];
    else cout << s[tmpi] << ' ' << s[tmpi + 1];

    return 0;
}


/*
    Algorithm : sort

    Time complexity : O(N)

*/