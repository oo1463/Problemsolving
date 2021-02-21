// https://www.acmicpc.net/problem/9934

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int K;
vector<int> v[11];
int arr[1025];

void recur(int start, int end, int cnt){
    if(start > end) return;
    int mid = (start + end) / 2;
    v[cnt].push_back(arr[mid]);
    recur(start, mid-1, cnt+1);
    recur(mid+1, end, cnt+1);
}

int main() {
    FAIO;
    cin >> K;
    
    for(int i=0; i<pow(2,K)-1; i++){
        cin >> arr[i];
    }

    recur(0, pow(2,K)-2, 0);

    for(int i=0; i<K; i++){
        for(int j=0; j<v[i].size(); j++) cout << v[i][j] << ' ';
        cout << el;
    }

    return 0;
}



/*
    Algorithm : recursion

    Time complexity : O(K)
    
*/
