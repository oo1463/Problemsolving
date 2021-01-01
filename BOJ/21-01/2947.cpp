// https://www.acmicpc.net/problem/2947

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

void print_arr(int arr[5]){
    for(int i=0; i<5; i++) cout << arr[i] << ' ';
    cout << el;
}

int main() {
    FAIO;
    
    int arr[5];

    for(int i=0; i<5; i++) cin >> arr[i];

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
                print_arr(arr);
            }
        }
    }
   
    return 0;
}



/*
    Algorithm : bubble sort

    Time complexity : O(N^2)
    
*/
