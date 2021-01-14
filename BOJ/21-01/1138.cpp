// https://www.acmicpc.net/problem/1138

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <list>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N;
list<int> l;

int main() {
    FAIO;
    int height[11];
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> height[i];
    }
    
    l.push_back(N);

    for(int i=N-2; i>=0; i--){
        int j = 0;
        for(auto a = l.begin(); a != l.end(); ){
            if(j == height[i]) {
                l.insert(a, i+1);
                break;
            }
            a++;
            j++;

            if(a == l.end()) l.push_back(i+1);
        }
    }

    for(auto a : l) cout << a << ' ';

    return 0;
}



/*
    Algorithm : list, 구현, greedy

    Time complexity : O(N^2)
    
*/
