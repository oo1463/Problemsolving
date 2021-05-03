// https://www.acmicpc.net/problem/1145

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

    int arr[5];
    for(int i=0; i<5; i++) cin >> arr[i];

    for(int i=1; i<1000000; i++){
        int cnt = 0;
        for(int j=0; j<5; j++){
            if(i%arr[j] == 0) cnt++;
        }
        if(cnt >= 3){
            cout << i;
            return 0;
        }
    }
   
    return 0;
}
