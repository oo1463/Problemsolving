// https://www.acmicpc.net/problem/11170

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int count_zero[1000001];

int check(int n){
    int sum = 0;
    if(n == 0) sum++;
    while(n>0){
        if(n%10 == 0) {
            sum++;
        }
        n /= 10;
    }
    return sum;
}

int main() {
    FAIO;

    for(int i=0; i<1000001; i++){
        count_zero[i] = check(i);
    }

    int T;
    cin >> T;

    while(T--){
        
        int n,m;
        cin >> n >> m;
        int sum = 0;
        for(int i=n; i<=m; i++){
            sum += count_zero[i];
        }

        cout << sum << el;

    }
   
    return 0;
}


/*
    Algorithm : implement

    Time complexity : O(M-N)
    
*/
