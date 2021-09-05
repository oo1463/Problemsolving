// https://www.acmicpc.net/problem/3613

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
    cin >> s;

    string answer_st;
    bool java = false, cpp = false;

    for(int i=0; i<s.size(); i++){
        if(s[i] == '_') {
            cpp=true;            

            if(i == s.size()-1 || s[i+1] == '_' || (s[i+1] >='A' && s[i+1] <= 'Z')){
                cout << "Error!" << el;
                return 0;
            }
        }
        if(s[i] >= 'A' && s[i] <= 'Z') java = true;
    }

    if(cpp&java){
        cout << "Error!" << el;
        return 0;
    }

    if(cpp){
        if(s[0] == '_'){
            cout << "Error!" << el;
            return 0;
        }
        for(int i=0; i<s.size(); i++){
            if(s[i] == '_'){
                answer_st += s[i+1] - 32;                
                i++;
            }
            else{
                answer_st += s[i];
            }
        }
    }

    if(java){
        
        if(s[0] >= 'A' && s[0] <='Z'){
            cout << "Error!" << el;
            return 0;
        }

        for(int i=0; i<s.size(); i++){
            if(s[i] >= 'A' && s[i] <='Z'){
                answer_st += '_';
                answer_st += s[i] + 32;                                
            }            
            else{
                answer_st += s[i];
            }
        }
    }

    if(java == false && cpp == false){
        answer_st = s;
    }

    cout << answer_st << el;
   
    return 0;
}


/*
    Algorithm : implement

    Time complexity : O(N)
    
*/
