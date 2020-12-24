// https://www.acmicpc.net/problem/1913

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, K;
int map[1000][1000];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

int main() {
    FAIO;

    cin >> N;
    cin >> K;
    
    map[N/2][N/2] = 1;
    int nowx = N/2;
    int nowy = N/2;
    int direct = 0;
    int cnt = 1;
    int kx,ky;

    while(cnt < N*N){
        cnt++;
        int right = (direct + 1) % 4;
        int tx = nowx + dx[right];
        int ty = nowy + dy[right];
        

        if(map[tx][ty] == 0){  // if right position is empty then move right
            nowx = tx;
            nowy = ty;
            direct = right;
        }
        else{  // move forward
            nowx = nowx + dx[direct];
            nowy = nowy + dy[direct];
        }

        map[nowx][nowy] = cnt;
        
        if(cnt == K){
            kx = nowx;
            ky = nowy;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << map[i][j] << ' ';
        }
        cout << el;
    }

    cout << kx+1 << ' ' << ky+1;
    return 0;
}



/*
    Algorithm : 구현

    Time complexity : O(N^2)
    
*/
