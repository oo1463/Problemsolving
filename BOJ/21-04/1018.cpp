// https://www.acmicpc.net/problem/1018

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int n,m;
char map[51][51];
char bw[8][8];
char wb[8][8];
int mn = 99999;

void min_change(int r, int c){
    int cnt1 = 0, cnt2 = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(map[i+r][j+c] == bw[i][j]) cnt1++;
            if(map[i+r][j+c] == wb[i][j]) cnt2++;
        }
    }
    if(mn > cnt1) mn = cnt1;
    if(mn > cnt2) mn = cnt2;
}

int main() {
    FAIO;

    cin >> n >> m;

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if((i+j)%2 == 0) {
                bw[i][j] = 'B';
                wb[i][j] = 'W';
            }
            else {
                bw[i][j] = 'W';
                wb[i][j] = 'B';
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0; i<=n-8; i++){
        for(int j=0;j<=m-8; j++){
            min_change(i,j);
        }
    }

    cout << mn;
   
    return 0;
}



/*
    Algorithm : bruteforce

    Time complexity : O((NM)^2)
    
*/
