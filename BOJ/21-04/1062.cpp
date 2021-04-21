// https://www.acmicpc.net/problem/1062

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N,K;
int s[51];
string ss[51];
int bit_mask = (1 << 'a'-'a') | (1 << 'n'-'a') | (1 << 't'-'a') | (1 << 'i' - 'a') | (1 << 'c'-'a');
int mx = 0;

void dfs(int si, int cnt){
    if(cnt == K){
        int cnt = 0;
        for(int i=0; i<N; i++){
            if((bit_mask & s[i]) == s[i]) cnt++;
        }

        if(mx < cnt) mx = cnt;
        return;
    }

    for(int i=si; i<26; i++){
        if((bit_mask & (1 << i)) == 0){
            bit_mask = bit_mask | (1 << i);
            dfs(i+1, cnt+1);
            bit_mask = bit_mask ^ (1 << i);
        }
    }
}

int main() {
    FAIO;
    
    cin >> N >> K;
    for(int i=0; i<N; i++){
        string ts;
        cin >> ts;
        ss[i] = ts;
        int sz = ts.size();
        for(int j=0; j<sz; j++) s[i] |= 1 << (ts[j]-'a');
    }
    if(K < 5) mx = 0;
    else{
        dfs(0,5);
    }

    cout << mx;
   
    return 0;
}


/*
    Algorithm : String, bitmasking, backtracking

    Time complexity : O(N * 21CK)
    
*/
