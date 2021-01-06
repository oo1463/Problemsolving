// https://www.acmicpc.net/problem/4659

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

map<char, bool> m;

bool check_1(string s){
    for(auto a : s){
        if( m[a] == true ){
            return true;
        }
    }
    return false;
}

bool check_2(string s){
    int flag = 1;
    for(int i=1; i<s.size() ;i++){        
        if(m[s[i-1]] == m[s[i]]) flag++;
        else flag = 1;
        
        if(flag == 3) return false;
    }
    return true;
}

bool check_3(string s){
    int flag = 1;
    for(int i = 1; i<s.size(); i++){
        if(s[i-1] == s[i]){
            if(s[i] == 'e' || s[i] == 'o') continue;
            else return false;
        }
    }
    return true;
}

int main() {
    FAIO;
    for(char i='a'; i<='z'; i++) {
        if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') m[i] = true;
    }
    while(1){
        string s;
        cin >> s;
        if(s == "end") break;

        if(check_1(s) && check_2(s) && check_3(s)){
            cout << '<' << s << '>' << " is acceptable." << el;
        }
        else{
            cout << '<' << s << '>' << " is not acceptable." << el;
        }

    }
   
    return 0;
}



/*
    Algorithm : 

    Time complexity : O(N^2)
    
*/
