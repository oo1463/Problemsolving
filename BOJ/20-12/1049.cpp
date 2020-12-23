// https://www.acmicpc.net/problem/1049

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N,M;
int cost[51][2];

int main() {
    FAIO;
    
    cin >> N >> M;


    for(int i=0; i<M; i++) cin >>cost[i][0] >> cost[i][1];
    int mn1=1001, mn2=1001;
    for(int i=0; i<M; i++){
        if(cost[i][0] < mn1) mn1 = cost[i][0];
        if(cost[i][1] < mn2) mn2 = cost[i][1];
    }

    int mx_buy;
    for(int i=0; i<N;i++) if(i * 6 > N) {
        mx_buy = i;
        break;
    }
    int answer = 100000000;
    for(int i=mx_buy-1; i>=0; i--){
        if(i * mn1 + (N-6*i) * mn2 < answer) answer = i * mn1 + (N-6*i) * mn2;
    }
    if(mx_buy * mn1 < answer) answer = mx_buy * mn1;

    cout << answer;    
   
    return 0;
}


/*
    Algorithm : math

    Time complexity : O(M)
    
*/