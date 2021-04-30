// https://www.acmicpc.net/problem/2846

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
    int N; cin >> N;
    int arr[1001];

    for(int i=0; i<N; i++) cin >> arr[i];

    int prev = arr[0];
    int first = arr[0];
    int mx = 0;
    for(int i=1; i<N; i++){
        if(arr[i] > arr[i-1]){
            if(arr[i] - first > mx) {
                mx = arr[i] - first;
            }
        }        
        else first = arr[i];
        
    }
    cout << mx;
   
    return 0;
}
