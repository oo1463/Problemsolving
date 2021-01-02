// https://www.acmicpc.net/problem/14719

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int H, W;
int pool[501];

int main() {
    FAIO;

    cin >> H >> W;

    for(int i=0; i<W; i++) cin >> pool[i];
   
    int j = 0;
    int height = pool[0];
    int sum = 0;
    for(int i=1; i<W; i++){
        if(height <= pool[i]) {
            for(int k=j+1; k < i; k++){
                sum += height - pool[k];
                pool[k] = height;
            }
            height = pool[i];            
            j = i;
        }
    }

    j = W-1;
    height = pool[j];
    
    for(int i=W-1; i>=0; i--){
        if(height <= pool[i]){
            for(int k = j-1; k>i; k--){
                sum += height - pool[k];
                pool[k] = height;
            }
            height = pool[i];            
            j = i;
        }
    }

    cout << sum;

    return 0;
}


/*
    Algorithm : simulation, implementation

    Time complexity : O(W)
    
*/
