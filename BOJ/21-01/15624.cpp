// https://www.acmicpc.net/problem/15624

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int fibo[1000001];

int main() {
    FAIO;

    int n;
    cin >> n;

    fibo[0] = 0;
    fibo[1] = 1;
    
    for(int i=2; i<=n; i++){
        fibo[i] = (fibo[i-1] + fibo [i-2]) % 1000000007;
    }

    cout << fibo[n];


   
    return 0;
}


/*
    Algorithm : DP

    Time complexity : O(N)
    
*/
