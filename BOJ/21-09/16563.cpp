// https://www.acmicpc.net/problem/16563

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

bool prime[5000001];
string pr[5000001];

void che(){
    for(long long i=2; i<5000001; i++){
        if(prime[i]){
            pr[i] = to_string(i);
            for(long long j=i+i; j<5000001; j+=i){
                prime[j] = false;
                long long tmp = j;
                while(tmp>1 && tmp%i==0){
                    pr[j] += pr[i] + " ";
                    tmp/=i;
                }
            }
        }
    }
}

int main() {
    FAIO;
    for(int i=2; i<5000001; i++){
        prime[i] = true;
    }

    che();

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int t;
        cin >> t;
        cout << pr[t] << el;
    }
    
    return 0;
}


/*
    Algorithm : eratosthenes

    Time complexity : O(NloglogN)
    
*/
