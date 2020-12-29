// https://www.acmicpc.net/problem/18111

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int map[501][501];
int N,M,B;

int count_ground_dig(int m[501][501], int floor){
    int cnt = 0;
    int b = B;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(m[i][j] < floor){
                b -= (floor-m[i][j]);
                cnt += floor - m[i][j];
            }
            else if(m[i][j] > floor){
                b += (m[i][j] - floor);
                cnt += 2 * (m[i][j] - floor);
            }
        }
    }
    if(b < 0) return -1;
    return cnt;
}

int main() {
    FAIO;
    
    cin >> N >> M >> B;

    int mn = 256, mx = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
            if(map[i][j] > mx) mx = map[i][j];
            if(map[i][j] < mn) mn = map[i][j];
        }
    }

    int mn_time = 2*500*500*256;
    int mn_floor;
    for(int i=mn; i<=mx; i++){
        int tmp;
        tmp = count_ground_dig(map, i);
        // cout << tmp << el;
        if(tmp <= mn_time && tmp != -1) {
            mn_time = tmp;
            mn_floor = i;
        }
    }
    
    cout << mn_time << ' ' << mn_floor;

    return 0;
}



/*
    Algorithm : implementation, brute force

    Time complexity : O(N^2)

    최악의 경우 C * 500 * 500 * 256 = C * 64,000,000 번의 연산이 필요
    
*/
