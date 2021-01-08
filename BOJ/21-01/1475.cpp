// https://www.acmicpc.net/problem/1475

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

string N;

int main() {
    FAIO;

    cin >> N;
    int cnt[10];
    memset(cnt,0,sizeof(cnt));

    for(auto a : N){
        if(a == '6' || a == '9'){
            cnt[6]++;
        }
        else cnt[a-'0'] += 2;
    }
    double mx = 0;
    for(int i=0; i<10; i++){
        if(mx < cnt[i]) mx = cnt[i];
    }    

    cout << ceil(mx/2);

    return 0;
}



/*
    Algorithm : implementation

    Time complexity : O(N)
    
*/
