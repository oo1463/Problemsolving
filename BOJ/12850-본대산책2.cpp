// https://www.acmicpc.net/problem/12849

//시간제한  메모리
//1 초	512 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int d;
long long adj[9][9] = { 
    { 0,0,0,0,0,0,0,0,0 }, 
    {0,0,1,1,0,0,0,0,0}, 
    {0,1,0,1,1,0,0,0,0}, 
    {0,1,1,0,1,1,0,0,0},
    {0,0,1,1,0,1,1,0,0},
    {0,0,0,1,1,0,1,1,0},
    {0,0,0,0,1,1,0,0,1},
    {0,0,0,0,0,1,0,0,1},
    {0,0,0,0,0,0,1,1,0,} 
    };
long long E[9][9] = { { 1,0,0,0,0,0,0,0,0 }, { 0,1,0,0,0,0,0,0,0 }, { 0,0,1,0,0,0,0,0,0 }, { 0,0,0,1,0,0,0,0,0 },{ 0,0,0,0,1,0,0,0,0 },{ 0,0,0,0,0,1,0,0,0 },{ 0,0,0,0,0,0,1,0,0 },{ 0,0,0,0,0,0,0,1,0 },{ 0,0,0,0,0,0,0,0,1 } };

void multi(long long mat1[9][9], long long mat2[9][9], void *mat) {
    
    long long tmpm[9][9];    
    memset(tmpm, 0, sizeof(tmpm));
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            for (int k = 1; k < 9; k++) {
                tmpm[i][j] += mat1[i][k] * mat2[k][j];
            }
            tmpm[i][j] = tmpm[i][j] % 1000000007;
        }
    }
    memcpy(mat, tmpm, sizeof(adj));
}

int main() {
    FAIO;

    cin >> d;

    int e = d;
    long long matrix[9][9];
    long long cc[9][9];
    memcpy(matrix, adj, sizeof(matrix));
    memcpy(cc, E, sizeof(cc));
    
    while (e != 1) {
        if (e % 2 == 0) {
            e /= 2;
            multi(matrix, matrix, matrix);
        }
        else {
            e = (e - 1) / 2;
            
            multi(cc, matrix, cc);
            multi(matrix, matrix, matrix);
        }
    }

    multi(cc, matrix, matrix);

    cout << matrix[1][1];

    return 0;
}


/*
    Algorithm : Divide & conquer

    Time complexity : O(logd)

*/