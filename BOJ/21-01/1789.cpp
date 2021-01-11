// https://www.acmicpc.net/problem/1789

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;


int main() {
    FAIO;

    long long S;

    cin >> S;

    

    long long answer = (sqrt(8*S + 1) - 1)/2;

    cout << answer;
    
    return 0;
}



/*
    Algorithm : math

    Time complexity : O(1)
    
*/
