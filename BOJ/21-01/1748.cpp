// https://www.acmicpc.net/problem/1748

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

    string N;
    cin >> N;
    int digit = N.size();

    long long answer = 0;

    for(int i=1; i<=digit-1; i++){
        answer += i * (9*(pow(10,i-1)));
    }

    answer += digit * (stoi(N) - (pow(10,digit-1)-1));

    cout << answer;

   
    return 0;
}



/*
    Algorithm : implementation , math

    Time complexity : O(logN)
    
*/
