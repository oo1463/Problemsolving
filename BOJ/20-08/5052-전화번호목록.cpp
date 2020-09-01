// https://www.acmicpc.net/problem/5052

//시간제한  메모리
//1 초	256 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int T, N;
string s[10001];

int main() {
    FAIO;

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) cin >> s[i];
        sort(s, s + N);
        for (int i = 0; i < N-1; i++) {
            size_t a = s[i].length();
            size_t b = s[i + 1].length();
            if (a > b) {
                string tmps = s[i].substr(0,b);
                if (tmps == s[i + 1]) {
                    cout << "NO" << el;
                    break;
                }
            }
            else if (a < b) {

                string tmps = s[i+1].substr(0,a);

                if (tmps == s[i]) {
                    cout << "NO" << el;
                    break;
                }
            }
            if (i == N - 2) cout << "YES" << el;
        }
    }

    return 0;
}


/*
    Algorithm : string

    Time complexity : O(N^2)

*/