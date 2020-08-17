// https://www.acmicpc.net/problem/9251

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

int dp[1002][1002];


int main() {
    FAIO;
    string s1, s2;
    memset(dp, 0, sizeof(dp));
    cin >> s1;
    cin >> s2;

    int l1 = s1.length();
    int l2 = s2.length();

    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < l2; j++) {
            if (s1[i] == s2[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
            else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);

        }
    }

    int k = 0;
    vector<char> v;
    //vector<char> v2;

    for (int i = 0; i < l1; i++) {
        for (int j = k; j < l2; j++) {
            if (s1[i] == s2[j]) {
                v.push_back(s1[i]);
                k = j + 1;
                break;
            }
        }
    }

    k = 0;
    for (int i = 0; i < l2; i++) {
        for (int j = k; j < l1; j++) {
            if (s1[i] == s2[j]) {
                v2.push_back(s1[i]);
                k = j + 1;
                break;
            }
        }
    }



    cout << dp[l1][l2];

    for (int i = 0; i < v.size(); i++) cout << v[i];

    return 0;
}


/*
    Algorithm : dp

    Time complexity : O(NM)

*/