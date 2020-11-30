// https://www.acmicpc.net/problem/17413

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

string s;

int main() {
    FAIO;

    getline(cin, s);

    int j = 0;
    for (int i = 0, j = 0; i < s.length(); i++) {
        
        if (s[i] == '<') {
            reverse(s.begin() + j, s.begin() + i);
            i++;
            while (s[i] != '>') i++;
            j = i+1;
        }
        else if (s[i] == ' ' || i == s.length()-1) {
            if (i == s.length() - 1) i++;
            reverse(s.begin() + j, s.begin() + i);
            j = i + 1;
        }
    }
    cout << s << endl;
    return 0;
}


/*
    Algorithm :
    Time complexity : O(N^2)

*/