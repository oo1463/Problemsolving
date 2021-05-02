// https://www.acmicpc.net/problem/21567

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

    long long a,b,c;
    cin >> a >> b >> c;
    long long mult = a * b * c;

    int use[10];
    for(int i=0; i<10; i++) use[i] = 0;

    while(mult > 0){
        use[mult%10]++;
        mult /= 10;
    }

    for(int i=0; i<10; i++) cout << use[i] << el;
   
    return 0;
}