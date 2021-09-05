// https://www.acmicpc.net/problem/11170

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

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

    int T;
    cin >> T;

    while(T--){
        
        int n,m;
        cin >> n >> m;
        int sum = 0;
        for(int i=n; i<=m; i++){
            sum += check(i);
        }

        cout << sum << el;

    }
   
    return 0;
}


/*
    Algorithm : implement

    Time complexity : O(M-N)
    
*/
