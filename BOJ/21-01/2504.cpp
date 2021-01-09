// https://www.acmicpc.net/problem/2504

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

stack<int> st;

int main() {
    FAIO;

    string s;
    cin >> s;

    // '(' --> -1 , ')' --> -2 ,  '[' --> -3 , ']' --> -4

    bool poss = 1;

    for(auto a : s){
        if(a == '(') st.push(-1);
        else if(a == '[') st.push(-3);
        else if(a == ')'){
            if(st.empty()) {
                poss = 0;
                break;
            }
            else {
                int sum = 0;
                while(st.top() > 0 && !st.empty()){
                    sum += st.top();
                    st.pop();
                    if(st.empty()) {
                        cout << 0;
                        return 0;
                    }
                }
                if(st.top() == -1){
                    st.pop();
                    if(sum != 0) st.push(sum*2);
                    else st.push(2);
                }
                else if(st.top() != -1){
                    cout << 0;
                    return 0;
                }
            }
        }
        else if(a == ']'){
            if(st.empty()) {
                cout << 0;
                return 0;
            }
            else {
                int sum = 0;
                while(st.top() > 0 && !st.empty()){
                    sum += st.top();
                    st.pop();
                    if(st.empty()) {
                        cout << 0;
                        return 0;
                    }
                }
                if(st.top() == -3){
                    st.pop();
                    if(sum != 0) st.push(sum*3);
                    else st.push(3);
                }
                else if(st.top() != -3){
                    cout << 0;
                    return 0;
                }
            }
        }

    }

    int sum = 0;

    while(!st.empty()){
        if(st.top() < 0){
            cout << 0;
            return 0;
        }
        sum+= st.top();
        st.pop();
    }
    cout << sum;
       
    return 0;
}



/*
    Algorithm : implementation , stack

    Time complexity : O(N)
    
*/
