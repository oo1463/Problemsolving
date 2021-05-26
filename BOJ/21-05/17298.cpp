// https://www.acmicpc.net/problem/17298

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int arr[1000001];
int answer[1000001];

stack<int> s1;
stack<int> s2;

int main() {
    FAIO;

    int N; cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    memset(answer, -1, sizeof(answer));
    s1.push(arr[0]);
    s2.push(0);

    for(int i=1; i<N; i++){
        while(!s1.empty() && s1.top() < arr[i]){
            answer[s2.top()] = arr[i];
            s1.pop();
            s2.pop();
        }
        s1.push(arr[i]);
        s2.push(i);
    }    

    for(int i=0; i<N; i++) cout << answer[i] << ' ';
   
    return 0;
}


/*
    Algorithm : stack

    Time complexity : O(N)
    
*/
