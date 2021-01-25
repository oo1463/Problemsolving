// https://www.acmicpc.net/problem/10157

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int direction;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int map[1001][1001];

int main() {
    FAIO;

    int C, R, K;

    cin >> C >> R >> K;
    direction = 0;
    int tx = 1;
    int ty = 1;
    int cnt = 2;
    map[1][1] = 1;

    if(K > R * C) {
        cout << "0";
        return 0;
    }

    if(K==1){
        cout << tx << ' ' << ty;
        return 0;
    }

    while(cnt <= R * C){
        tx = tx + dx[direction];
        ty = ty + dy[direction];
        if(tx > C || ty > R || tx <= 0 || ty <= 0 || map[tx][ty] != 0) {
            tx -= dx[direction];
            ty -= dy[direction];
            direction = (direction+1) % 4;
            cnt--;
        }
        if(cnt == K){
            cout << tx << ' ' << ty ;
            return 0;
        }
        map[tx][ty] = cnt;
        cnt++;
    }
   
    return 0;
}



/*
    Algorithm : implementation

    Time complexity : O(RC)
    
*/
