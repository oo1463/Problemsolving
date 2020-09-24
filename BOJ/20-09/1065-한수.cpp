// https://www.acmicpc.net/problem/1065

//시간제한  메모리
//2 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;


bool check(int n) {
    string s = to_string(n);    

    if (n >= 1 && n <= 99) return true;
    else if (n > 99) {
        int i = s[0] - '0';
        int j = s[1] - '0';
        int k = s[2] - '0';
        if (i - j == j - k) return true;
        else return false;
    }
}

int N;

int main() {
    FAIO;
    int answer = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) if (check(i)) answer++;
    cout << answer;

    return 0;
}
