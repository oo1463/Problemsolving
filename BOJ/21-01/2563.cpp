// https://www.acmicpc.net/problem/2563

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
    
    int N;
    cin >> N;
    
    bool square[101][101];
    memset(square, false, sizeof(square));

    for(int i=0; i<N; i++){
        int x,y;
        cin >> x >> y;
        for(int i=x; i<x+10; i++){
            for(int j=y; j<y+10; j++){
                square[i][j] = true;
            }
        }
    }
    int sum_area = 0;

    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(square[i][j]) sum_area++;
        }
    }

    cout << sum_area;

   
    return 0;
}



/*
    Algorithm : implementation

    Time complexity : O(N)
    
*/
