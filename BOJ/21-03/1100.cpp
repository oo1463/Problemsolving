// https://www.acmicpc.net/problem/1100

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

    int cnt = 0;

    for(int i=0; i<8; i++){
        string s;
        cin >> s;
        for(int j=0; j<8; j++)                        
            if((i+j)%2 == 0 && s[j] == 'F') cnt++;
    }

    cout << cnt;
   
    return 0;
}
