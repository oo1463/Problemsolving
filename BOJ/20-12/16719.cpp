// https://www.acmicpc.net/problem/16719

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <list>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

string s;

int main() {
    FAIO;
    
    cin >> s;

    list<string> vs;
    vs.push_front(s);
    while(s.size()>1){
        for(int i=0; i<s.size()-1; i++){
            if(s[i] > s[i+1]){
                s.erase(i,1);
                vs.push_front(s);
                break;
            }
            if(i == s.size()-2){
                s.pop_back();
                vs.push_front(s);
            }
        }
    }

    for(auto a : vs) cout << a << el;
   
    return 0;
}



/*
    Algorithm : implementation
    
    Time complexity : O(N^2)
    
*/
