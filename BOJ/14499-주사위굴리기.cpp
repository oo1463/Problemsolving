// https://www.acmicpc.net/problem/14499

//시간제한  메모리
//2 초	512 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int map[21][21];
int d[7];
int td[7];
int N, M, K;
int nowx, nowy;

int north(int x, int y) {
    td[1] = d[5];    
    td[2] = d[1];
    td[3] = d[3];
    td[4] = d[4];
    td[5] = d[6];
    td[6] = d[2];
    if (map[x][y] == 0) {
        map[x][y] = td[6];
    }
    else {
        td[6] = map[x][y];
        map[x][y] = 0;
    }
    return td[1];
}

int south(int x, int y) {
    td[1] = d[2];
    td[2] = d[6];
    td[3] = d[3];
    td[4] = d[4];
    td[5] = d[1];
    td[6] = d[5];
    if (map[x][y] == 0) {
        map[x][y] = td[6];
    }
    else {
        td[6] = map[x][y];
        map[x][y] = 0;
    }
    return td[1];
}

int west(int x, int y) {
    td[1] = d[3];
    td[2] = d[2];
    td[3] = d[6];
    td[4] = d[1];
    td[5] = d[5];
    td[6] = d[4];
    if (map[x][y] == 0) {
        map[x][y] = td[6];
    }
    else {
        td[6] = map[x][y];
        map[x][y] = 0;
    }
    return td[1];
}

int east(int x, int y) {
    td[1] = d[4];
    td[2] = d[2];
    td[3] = d[1];
    td[4] = d[6];
    td[5] = d[5];
    td[6] = d[3];
    if (map[x][y] == 0) {
        map[x][y] = td[6];
    }
    else {
        td[6] = map[x][y];
        map[x][y] = 0;
    }
    return td[1];
}

int roll(int where, int x, int y) {
    int top = 0;
    switch (where) {
    case 1:
        top = east(x, y);
        break;
    case 2:
        top = west(x, y);
        break;
    case 3:
        top = north(x, y);
        break;
    case 4:
        top = south(x, y);
        break;
    }

    nowx = x;
    nowy = y;

    memcpy(d, td, sizeof(d));
    memset(td, 0, sizeof(td));

    return top;
}

int main() {
    FAIO;
    int sx, sy;
    cin >> N >> M >> sx >> sy >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    nowx = sx;
    nowy = sy;

    int go;
    while (K--) {
        cin >> go;
        int tmpx = nowx;
        int tmpy = nowy;
        if (go == 1) tmpy += 1;
        else if (go == 2) tmpy -= 1;
        else if (go == 3) tmpx -= 1;
        else tmpx += 1;
        if (tmpx < 0 || tmpy < 0 || tmpx >= N || tmpy >= M) continue;
        
        cout << roll(go, tmpx, tmpy) << el;
    }

    return 0;
}


/*
    Algorithm :

    Time complexity : O(K)

*/