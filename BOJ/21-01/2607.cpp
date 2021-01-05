// https://www.acmicpc.net/problem/2607

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int size_first;

bool check(map<char, int> m, string s){

    int sz = s.size();
    if(abs(size_first - sz > 1)) return false;

    map<char, int> ms;

    int cnt = 0;
    for(auto a : s){        
        m[a]--;
    }
    for(auto a : m){
        cnt += abs(a.second);
        // cout << a.second << ' ';
    }
    // cout << el;
    if(cnt > 2) return false;
    return true;

}

int main() {
    FAIO;

    int N;
    string s[101];
    map<char, int> m;

    cin >> N;

    for(int i=0; i<N; i++)cin >> s[i];
    for(auto a : s[0]) m[a]++;

    size_first = s[0].size();
    int cnt = 0;

    for(int i=1; i<N; i++){
        if(check(m, s[i])) cnt++;
    }
    
    cout << cnt;
    return 0;
}



/*
    Algorithm : string, implementation

    Time complexity : O(N)
    
*/
