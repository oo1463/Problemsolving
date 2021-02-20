// https://www.acmicpc.net/problem/10830

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

typedef struct mat{
    long long arr[6][6];
}mat;

int n;
long long b;
mat A;

void printM(mat a){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << a.arr[i][j] % 1000 << ' ';
        }
        cout << el;
    }
}

mat mult(mat a, mat b){
    mat newm;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            long long sum = 0;
            for(int k=0; k<n; k++){
                sum += a.arr[i][k] * b.arr[k][j];
            }
            newm.arr[i][j] = sum % 1000;
        }
    }
    return newm;
}

mat recur(mat a, long long b){
    if(b == 1) return a;
    if(b%2 == 0){
        mat tmp = recur(a,b/2);
        return mult(tmp, tmp);
    }
    else if(b % 2 == 1){
        mat tmp = recur(a,b/2);
        return mult(a ,mult(tmp,tmp));
    }
}

int main() {
    FAIO;

    cin >> n >> b;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> A.arr[i][j];
        }
    }

    mat tm = recur(A, b);

    printM(tm);
   
    return 0;
}


/*
    Algorithm : divide & conquer

    Time complexity : O(AlogB)
    
*/
