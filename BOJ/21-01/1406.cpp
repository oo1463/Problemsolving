// https://www.acmicpc.net/problem/1406

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <list>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

list<char> l;

int main() {
    FAIO;
    string s;
    cin >> s;

    for(auto a : s) l.push_back(a);

    auto cursor = l.end();

    int M;
    cin >> M;
    while(M--){
        char a;
        char addc;
        cin >> a;
        if(a == 'P') {
            cin >> addc;
            l.insert(cursor, addc);            
        }
        else{
            if(a == 'L' && cursor != l.begin()){
                cursor--;
            }
            else if(a == 'D' && cursor != l.end()){
                cursor++;
            }
            else if(a == 'B' && !l.empty() && cursor != l.begin()){
                auto er_cursor = --cursor;
                cursor++;                
                l.erase(er_cursor);                
            }
        }
        
    }
    for(auto a : l) cout << a;
    
    return 0;
}



/*
    Algorithm : implementation

    Time complexity : O(N + M)
    
*/
