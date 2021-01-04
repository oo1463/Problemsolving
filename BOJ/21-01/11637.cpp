// https://www.acmicpc.net/problem/11637

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

    int T;
    cin >> T;
    while(T--){
        int n;
        int votes[11];
        cin >> n;
        int sum = 0;
        int mx = 0;
        int ti = 0;
        for(int i=0; i<n; i++) {
            cin >> votes[i];
            sum += votes[i];
            if(mx < votes[i]){
                mx = votes[i];
                ti = i;
            }
            else if(mx == votes[i]){
                ti = -1;
            }
        }
        if(ti == -1){
            cout << "no winner" << el;
            continue;
        }
        else if(votes[ti] > sum/2){
            cout << "majority winner " << ti + 1 << el;
        }
        else {
            cout << "minority winner " << ti + 1 << el;
        }
    }
   
    return 0;
}



/*
    Algorithm : implementation

    Time complexity : O(Tn)
    
*/
