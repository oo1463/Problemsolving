// https://www.acmicpc.net/problem/2581

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, M;
bool is_prime[10001];

int main() {
    FAIO;

    cin >> M >> N;

    memset(is_prime, true, sizeof(is_prime));
    is_prime[1] = false;
    int sum = 0;
    int mn = 0;
    for(int i=2; i<=N; i++){
        if(is_prime[i]){            
            if(i >= M) {
                sum += i;
                if(mn == 0) mn = i;
            }
            for(int j=i*i; j<=N; j += i){
                is_prime[j] = false;
            }
        }
    }
    if(mn == 0) cout << -1;
    else{
        cout << sum << el;
        cout << mn;
    }
    
    return 0;
}



/*
    Algorithm : prime number

    Time complexity : O(NloglogN)
    
*/
