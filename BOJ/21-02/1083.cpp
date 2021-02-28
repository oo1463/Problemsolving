// https://www.acmicpc.net/problem/1083

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    FAIO;

    int n, s;
    int arr[51];
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cin >> s;

    int mx = arr[0];
    int pre_index = 0;
    int next_index = 0;
    
    while(s>0){

        mx = arr[pre_index];

        for(int i=pre_index+1; i<= pre_index+1 + s && i<n; i++){
            if(mx < arr[i]){
                mx = arr[i];
                next_index = i;
            }
        }
        cout << next_index << ' ' << pre_index << el;
        for(int i=next_index; i>pre_index; i--){
            swap(arr[i], arr[i-1]);
            --s;
        }
        if(next_index == pre_index) break;
        pre_index = next_index;
    }

    for(int i=0; i<n; i++) cout << arr[i] << ' ';
    
    return 0;
}



/*
    Algorithm : sort, greedy

    Time complexity : O(N^3)
    
*/
