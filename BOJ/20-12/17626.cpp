// https://www.acmicpc.net/problem/17676

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int main() {
    FAIO;

    int n;

    cin >> n;

    int answer = 3;
    for(int i=0; i<=224; i++){
        for(int j=i; j<=224; j++){
            for(int k=j; k<=224; k++){                
                if(i*i + j*j + k*k > n) break;
                else if(i*i + j*j + k*k == n){
                    if(i==0) answer--;
                    if(j==0) answer--;
                    if(k==0) answer--;
                    cout << answer;
                    return 0;
                }
                
            }
        }
    }    

    cout << 4;
    return 0;
}


/*
    Algorithm : backtracking

    Time complexity : O(root(n)^3)
    
*/