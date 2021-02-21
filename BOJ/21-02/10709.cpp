// https://www.acmicpc.net/problem/10709

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int main() {
    FAIO;

    int h, w;
    int map[101][101];
    memset(map, -1, sizeof(map));
    cin >> h >> w;
    for(int i=0; i<h; i++){
        string s;
        cin >> s;
        for(int j=0; j<w; j++){
            if(s[j] == 'c') map[i][j] = 0;
        }
    }

    for(int k=0; k<w; k++){
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(map[i][j] != -1 && map[i][j+1] == -1) map[i][j+1] = map[i][j] + 1;
            }
        }
    }

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cout << map[i][j] << ' ';
        }
        cout << el;
    }
   
    return 0;
}


/*
    Algorithm : implementation

    Time complexity : O(N^3)
    
*/
