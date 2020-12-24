// https://www.acmicpc.net/problem/2960

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N,K;

bool is_p[1001];

int main() {
    FAIO;
    
    cin >> N >> K;

    memset(is_p, true, sizeof(is_p));

    is_p[1] = false;    
    int cnt = 0;

    for(int i=2; i<=N; i++){
        if(is_p[i] == true){
            cnt++;
            if(cnt == K){
                cout << i;
                return 0;
            }
            for(int j=i*i; j<=N; j += i){
                if(is_p[j] == true){
                    is_p[j] = false;
                    cnt++;
                    if(cnt == K){
                        cout << j;
                        return 0;
                    }
                }
            }
        }
    }
    
   
    return 0;
}



/*
    Algorithm : Eratosthenes

    Time complexity : O(NloglogN)
    
*/
