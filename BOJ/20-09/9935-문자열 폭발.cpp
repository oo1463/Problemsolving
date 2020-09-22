// https://www.acmicpc.net/problem/9935

//시간제한  메모리
//2 초 (추가 시간 없음)	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

string s, b;

int main() {
    FAIO;

    cin >> s >> b;
    int bs = b.length();
    int len = s.length();

    for (int i = 0; i < len;) {
        int flag = 1;
        //cout << s << el;
        for (int k = i; k < i + bs && k < len; k++) {
            if (s[k] != b[k - i]) {
                flag = 1;
                break;
            }
            else flag = 0;
        }

        if (flag == 0) {
            s.erase(i, bs);
            if (i < bs) i = 0;
            else i -= bs ;
        }
        else i++;
        len = s.length();
    }

    if (!s.empty()) cout << s;
    else cout << "FRULA";

    return 0;
}


/*
    Algorithm : string

    Time complexity : O(S.length * B.length)

*/