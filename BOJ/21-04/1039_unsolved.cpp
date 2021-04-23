// https://www.acmicpc.net/problem/1039

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
    int N,K; cin >> N >> K;

    string s = to_string(N);    
    int sz = s.size();
    if(sz == 1 || (sz == 2 && s[1] == '0')){
        cout << -1;
        return 0;
    }

    int cnt = 0;
    for(int i=0; i<sz-1; i++){
        int mx = s[i];
        int index = i;
        for(int j=sz-1; j>i; j--){
            if(s[j] > mx){
                mx = s[j];
                index = j;
            }
        }
        string ps = s;
        if(index != i){
            swap(s[i], s[index]);
            cnt++;
        }
        if(cnt == K || ps == s) break;
    }
    if((K-cnt) % 2 == 0) cout << stoi(s);
    else {
        swap(s[sz-1], s[sz-2]);
        cout << stoi(s);
    }

    return 0;
}


/*
    Algorithm : selection sort, greedy

    Time complexity : O(N^2)
    
*/
