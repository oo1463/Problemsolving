// https://www.acmicpc.net/problem/1049

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N , M;

int main() {
    FAIO;

    cin >> N >> M;

    int package = 1111, piece = 1111;
    while(M--){
        int a,b;
        cin >> a >> b;
        if(package > a) package = a;
        if(piece > b) piece = b;
    }

    int mn = 1000000;

    for(int i=0; i * 6 <= 105; i++){
        for(int j=0; j <= 100; j++){
            if(6 * i + j >= N){
                if(i * package + j * piece < mn) mn = i * package + j * piece;
            }
        }
    }

    cout << mn;
   
    return 0;
}



/*
    Algorithm : bruteforce

    Time complexity : O(N^2)
    
*/
