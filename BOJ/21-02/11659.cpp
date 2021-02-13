// https://www.acmicpc.net/problem/11659

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, M;
int arr[100001];

int main() {
    FAIO;

    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    for(int i=0; i<N; i++) arr[i] = arr[i-1] + arr[i];
    
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        cout << arr[b-1] - arr[a-2] << el;
    }

    return 0;
}



/*
    Algorithm : sum

    Time complexity : O(N)
    
*/
