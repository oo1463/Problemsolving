// https://www.acmicpc.net/problem/1918

//시간제한  메모리
//2 초	128 MB

#include <iostream>
#include <algorithm>
#include <stack>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

string s;
stack<char> cs;

int main() {
    FAIO;

    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ')') {
            cout << cs.top();
            cs.pop();
        }
        else if (s[i] == '*' || s[i] == '+' || s[i] == '-' || s[i] == '/') cs.push(s[i]);
        else if (s[i] >= 'A' && s[i] <= 'Z' ) cout << s[i];

        if (i == s.length() - 1) {
            while (!cs.empty()) {
                cout << cs.top();
                cs.pop();
            }
        }
    }

    return 0;
}


/*
    Algorithm :

    Time complexity : O(N^2)

*/