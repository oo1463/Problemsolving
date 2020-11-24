// https://www.acmicpc.net/problem/1439

//시간 제한	메모리 제한
//2 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;


int main() {
    FAIO;

    string s;
    int cnt0 = 0;
    int cnt1 = 0;

    cin >> s;

    for (int i = 0; i < s.length();) {
        if (s[i] == '0') {
            cnt0++;
            int j;
            for (j = i + 1; j < s.length() && s[j] == '0'; j++);
            i = j;
        }
        else {
            cnt1++;
            int j;
            for (j = i + 1; j < s.length() && s[j] == '1'; j++);
            i = j;
        }
    }
    
    cout << (cnt0 < cnt1 ? cnt0 : cnt1);

    return 0;
}
