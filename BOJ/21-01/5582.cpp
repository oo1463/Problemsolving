// https://www.acmicpc.net/problem/5582

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

string s1, s2;
int dp[4001][4001];

int main() {
    FAIO;

    cin >> s1 >> s2;

    int sz1 = s1.size(), sz2 = s2.size();

    for(int i=0; i<sz1; i++){
        if(s1[i] == s2[0]) dp[i][0] = 1; 
    }

    for(int i=0; i<sz2; i++){
        if(s2[i] == s1[0]) dp[0][i] = 1;
    }

    int mx = 0;

    for(int i=1; i<sz1; i++){
        for(int j=1; j<sz2; j++){
            if(s1[i] == s2[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
                if(dp[i][j] > mx) mx = dp[i][j];
            }
        }
    }

    cout << mx;
   
    return 0;
}



/*
    Algorithm : String, DP

    Time complexity : O(N^2)
    
*/
