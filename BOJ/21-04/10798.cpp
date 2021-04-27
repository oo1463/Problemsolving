// https://www.acmicpc.net/problem/10798

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

    string s[5];

    for(int i=0; i<5; i++){
        cin >> s[i];
    }

    string ans="";
    for(int i=0; i<15; i++){
        for(int j=0; j<5; j++){
            if(s[j].size() > i) ans += s[j][i];
        }
    }

    cout << ans;
   
    return 0;
}


/*
    Algorithm : string
    
*/
