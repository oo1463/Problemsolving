// https://www.acmicpc.net/problem/12904

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

    string s;
    string t;
    
    cin >> s;
    cin >> t;
    bool flag = false;
    while(1){
        if(s.size() == t.size()){
            if(s == t) flag = true;
            break;
        }

        char lastC = t[t.size()-1];
        t.pop_back();
        if(lastC == 'B') reverse(t.begin(), t.end());
    }   

    cout << flag;
   
    return 0;
}



/*
    Algorithm : string , simulation

    Time complexity : O(st)
    
*/
