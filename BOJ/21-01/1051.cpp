// https://www.acmicpc.net/problem/1051

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int small(int a, int b){return a<b?a:b;}

string arr[51];

int main() {
    FAIO;

    int N, M;
    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    int sm = small(N,M);
    int mx = 1;

    for(int i=2; i<=sm; i++){
        for(int j=0; j<N-i+1; j++){
            for(int k=0; k<M-i+1; k++){
                int num = arr[j][k];
                if(num == arr[j+i-1][k] && num == arr[j][k+i-1] && num == arr[j+i-1][k+i-1]) mx = i;
            }
        }
    }
    cout << mx*mx;

   
    return 0;
}



/*
    Algorithm : bruteforce

    Time complexity : O(N^3)
    
*/
