// https://www.acmicpc.net/problem/2631

//시간제한  메모리
//1 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N;
int a[201];
int d[201];


int main() {
    FAIO;

    cin >> N;
    int cnt = 0; 
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    int i, j, max = 0;
    for (i = 1; i <= N; i++) {
        d[i] = 1;
        for (j = 1; j < i; j++)
            if (a[j] < a[i] && d[i] < d[j] + 1)
                d[i]++;
        if (max < d[i]) max = d[i];
    }

    cout << N-max;
    return 0;
}
