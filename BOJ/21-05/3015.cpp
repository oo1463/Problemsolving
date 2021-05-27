// https://www.acmicpc.net/problem/3015

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int num[500001];
stack<int> st;
stack<int> st2;

int main() {
    FAIO;

    int N; cin >> N;

    for(int i=0; i<N; i++){
        cin >> num[i];
    }

    st.push(num[0]);
    st2.push(1);
    long long ans = 0;
    for(int i=1; i<N; i++){    
        int cnt = 0;        

        if(st.top() > num[i]) ans++;
        
        while(!st.empty() && st.top() <= num[i]){
            ans += st2.top();
            if(st.top() == num[i]) cnt = st2.top();
            st.pop();
            st2.pop();
            if(!st.empty() && st.top() > num[i]) ans++;
        }
        st.push(num[i]);
        st2.push(cnt+1);
    }

    cout << ans;
   
    return 0;
}


/*
    Algorithm : stack

    Time complexity : O(N)
    
*/
