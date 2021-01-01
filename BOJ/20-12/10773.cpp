// https://www.acmicpc.net/problem/10773

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <list>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int K;

int main() {
    FAIO;

    cin >> K;    

    list<int> l;

    int sum = 0;
    while(K--){
        int ti;
        cin >> ti;
        if(ti != 0) l.push_back(ti);
        else{
            l.pop_back();
        }
    }
    
    for(auto a : l) sum += a;

    cout << sum;

    return 0;
}



/*
    Algorithm : list, implementation

    Time complexity : O(K)
    
*/
