// https://www.acmicpc.net/problem/2303

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N;
int card[1001][5];
int draw[3];
int mx[1001];

void backtracking(int who, int si, int di){
    if(si == 3){
        int sum = 0;
        for(int i=0; i<3; i++) sum += draw[i];
        if(mx[who] < sum % 10) mx[who] = sum % 10;
        // cout << draw[0] << draw[1] << draw[2] << el;
        return;
    }

    for(int i = di; i<5; i++){
        draw[si] = card[who][i];
        backtracking(who, si + 1, i+1);
    }
}

int main() {
    FAIO;

    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<5; j++) cin >> card[i][j];
    }
    
    for(int i=0; i<N; i++){
        backtracking(i,0,0);
    }

    int sum_mx = 0;
    int ti;
    for(int i=0; i<N; i++){
        if(sum_mx <= mx[i]){
            sum_mx = mx[i];
            ti = i;
        }
    }

    cout << ti + 1;

    return 0;
}



/*
    Algorithm : backtracking

    Time complexity : O(N)
    
*/
