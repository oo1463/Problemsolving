// https://www.acmicpc.net/problem/9461

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

    int T, N;
    long long p[101];

    p[1] = 1;
    p[2] = 1;
    p[3] = 1;
    p[4] = 2;
    p[5] = 2;
    for (int i = 6; i <= 100; i++) p[i] = p[i - 1] + p[i - 5];
    
    cin >> T;
    while (T--) {
        cin >> N;
        cout << p[N] << el;
    }


    return 0;
}


/*
    Algorithm :

    Time complexity : O(N^2)

*/