// https://www.acmicpc.net/problem/1431

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

string s[1001];

bool compare(string a, string b){
    int sz1 = a.size();
    int sz2 = b.size();
    if(sz1 != sz2) return sz1 < sz2;

    int cnt1 = 0;
    int cnt2 = 0;
    for(int i=0; i<sz1; i++){
        if(a[i] >= '0' && a[i] <= '9') cnt1 += a[i]-'0';
        if(b[i] >= '0' && b[i] <= '9') cnt2 += b[i]-'0';
    }
        
    if(cnt1 != cnt2) {
        return cnt1 < cnt2;
    }
    
    return a < b;
}

int main() {
    FAIO;
    int N; cin >> N;
    for(int i=0; i<N; i++) cin >> s[i];

    sort(s, s+N, compare);
    
    for(int i=0; i<N; i++) cout << s[i] << el;
    return 0;
}


/*
    Algorithm : string, sort

    Time complexity : O(NlogN)
    
*/
