// https://www.acmicpc.net/problem/2908

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
    string a, b;
    cin >> a >> b;

    for(int i=0; i<a.size()/2; i++){
        swap(a[i], a[a.size()-i-1]);
    }

    
    for(int i=0; i<b.size()/2; i++){
        swap(b[i], b[b.size()-i-1]);
    }

    if(stoi(a)>stoi(b)){
        cout << a;
    }
    else cout << b;

    return 0;
}