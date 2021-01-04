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

    for(int i=1; i<99; i++){
        for(int j=1; j<99; j++){
            for(int k=1; k<99; k++){
                if(i+j+k == 100) cout << i << ' ' << j << ' ' << k << el;                
            }
        }
    }
   
    return 0;
}

