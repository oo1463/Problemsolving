// https://www.acmicpc.net/problem/1783

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

    int n,m;

    cin >> n >> m;

    int ans = 0;

    if(n == 1) ans = 1;
    else if(n < 3){
        if(m < 3) ans = 1;
        else if(m < 7){
            ans = (m+1)/2;
        }
        else ans = 4;
    }
    else{
        if(m < 4) ans = m;
        else if(m > 6) ans = m-2;
        else ans = 4;
    }

    cout << ans;
   
    return 0;
}



/*
    Algorithm : implementation

    Time complexity : O(1)
    
*/
