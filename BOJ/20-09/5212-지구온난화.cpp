// https://www.acmicpc.net/problem/5212

//시간제한  메모리
//1 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int r, c;
string s[10];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1 ,0, -1 };
int cnt[10][10];
int main() {
    FAIO;
    
    cin >> r >> c;
    for (int i = 0; i < r; i++) cin >> s[i];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (s[i][j] == 'X') {                
                for (int k = 0; k < 4; k++) {
                    int tmpx = i + dx[k];
                    int tmpy = j + dy[k];
                    if (tmpx < 0 || tmpx >= r || tmpy < 0 || tmpy >= c) cnt[i][j]++;
                    else if (s[tmpx][tmpy] == '.') cnt[i][j]++;
                }
            }
        }
    }

    int minx = 11, miny = 11, maxx = 0, maxy = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (cnt[i][j] >= 3) s[i][j] = '.'; 
            if (s[i][j] == 'X') {
                if (i < minx) minx = i;
                if (i > maxx) maxx = i;
                if (j < miny) miny = j;
                if (j > maxy) maxy = j;
            }
        }
    }

    for (int i = minx; i <= maxx; i++) {
        for (int j = miny; j <= maxy; j++) {
            cout << s[i][j];
        }
        cout << el;
    }

    return 0;
}


/*
    Algorithm : simulation

    Time complexity : O(RC)

*/