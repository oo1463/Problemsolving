// https://www.acmicpc.net/problem/1292

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

    int a,b;
    cin >> a >> b;
    vector<int> v;
    int sz = 0;
    for(int i=1; i<1001 && sz <= b; i++){
        for(int j=0; j<i; j++) {
            v.push_back(i);
            sz++;
        }
    }
    int sum = 0;
    for(int i=a-1; i<b; i++){
        sum += v[i];
    }

    cout << sum;
   
    return 0;
}