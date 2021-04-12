// https://www.acmicpc.net/problem/1099

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

string s;
int n;
string words[51];
int dp[51];


bool can_make(string s1, string s2){
    int check1[26];
    int check2[26];
    int sz = s1.size();
    if(s1.size() != s2.size()) return false;
    for(int i=0; i<26; i++) {
        check1[i] = 0;
        check2[i] = 0;
    }
    
    for(int i=0; i<sz; i++){
        check1[s1[i]-'a']++;
        check2[s2[i]-'a']++;
    }
    for(int i=0; i<26; i++) if(check1[i] != check2[i]) return false;

    return true;
}

int count_dist(string s1, string s2){
    if(!can_make(s1,s2)) return -1;

    int cnt = 0;
    int sz = s1.size();
    for(int i=0; i<sz; i++){
        if(s1[i] != s2[i]) cnt++;
    }    

    return cnt;
}

int main() {
    FAIO;

    cin >> s;
    cin >> n;
    for(int i=0; i<n; i++) cin >> words[i];
    int distance[51][51];
    int ssz = s.size();
    for(int i=0; i<ssz; i++){
        for(int j=0; j<ssz; j++) distance[i][j] = 51;
    }
    for(int i=0; i<ssz; i++) dp[i] = 51;
   
    for(int i=0; i<ssz; i++){
        for(int j=i; j<ssz; j++){
            string ts = s.substr(i,j-i+1);
            for(int k=0; k<n; k++){
                int dist = count_dist(ts, words[k]);
                if(dist != -1 && distance[i][j] > dist) distance[i][j] = dist;
            }
        }
    }
    
    for(int i=0; i<ssz; i++){
        if(distance[0][i] != 51 && dp[i] > distance[0][i]) dp[i] = distance[0][i]; 
        for(int j=0; j<i; j++){
            if(dp[j] != 51 && distance[j+1][i] != 51 && dp[i] > dp[j]+distance[j+1][i]) dp[i] = dp[j]+distance[j+1][i];
        }
    }
    
    if(dp[ssz-1] != 51) cout << dp[ssz-1];
    else cout << -1;

    return 0;
}



/*
    Algorithm : dp

    Time complexity : O(length^3)
    
*/
