// https://www.acmicpc.net/problem/10808

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
    int alpha[26];
    memset(alpha, 0, sizeof(alpha));
    cin >> s;

    for(auto a : s) alpha[a-'a']++;

    for(auto a : alpha) cout << a << ' ';

   
    return 0;
}