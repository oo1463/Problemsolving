// https://www.acmicpc.net/problem/1078

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int reverse(int s){

    int digit = 0;
    for(int i=1; i<10; i++){
        if(s/(int)pow(10,i) == 0) {
            digit = i;
            break;
        }
    }

    double inversed = 0;

    for(int i=0; i<digit; i++){
        inversed += (int)(s % 10)*pow(10,digit-i-1);
        s /= 10;
    }

    return inversed;
}

int main() {
    FAIO;

    int d;
    cin >> d;

    // cout << reverse(1010100) << el;

    for(int i=1; i<2000000; i++){
        
        int rev = reverse(i);
        if(i-rev < 0) continue;

        // cout << i << ' ' << ' ' << rev << ' ' << i-rev << el;
        if(i-rev == d) {
            cout << i;
            return 0;
        }
    }

    cout << -1;
   
    return 0;
}


/*
    Algorithm : 

    Time complexity : O(N^2)
    
*/
