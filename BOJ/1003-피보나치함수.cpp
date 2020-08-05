// https://www.acmicpc.net/problem/1003

//시간제한      메모리
// 0.25 초 (추가 시간 없음)	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int f[41];
int count1[41], count2[41];

int fibonacci(int n) {    
    f[0] = 1;
    f[1] = 1;
    count1[0] = 1;
    count2[0] = 0;
    count1[1] = 0;
    count2[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
        count1[i] = count1[i - 1] + count1[i - 2];
        count2[i] = count2[i - 1] + count2[i - 2];
    }
    return f[n];
}



int main() {
    int N;
    int t;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> t;
        fibonacci(t);
        cout << count1[t] << ' ' << count2[t] << endl;
    }
    
    return 0;
}

/*
    Algorithm : Dynamic Programming

    Time complexity : O(Nt)

*/