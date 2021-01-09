// https://www.acmicpc.net/problem/7568

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int compare(pair<int, int> a, pair<int, int> b){
    if(a.first > b.first && a.second > b.second){
        return 1;
    }
    else if(a.first < b.first && a.second < b.second) {
        return -1;
    }
    else
        return 0;
}

int main() {
    FAIO;

    int N;
    pair<int, int> p[51];
    pair<int, int> tp[51];

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> p[i].first >> p[i].second;
    }

    for(int i=0; i<N; i++){
        int cnt = N;
        for(int j=0; j<N; j++){
            if(j != i){
                if(compare(p[i], p[j]) == -1){
                    continue;
                }
                else cnt--;
            }
        }
        cout << cnt << ' ';
    }
    
   
    return 0;
}



/*
    Algorithm : implementation

    Time complexity : O(N^2)
    
*/
