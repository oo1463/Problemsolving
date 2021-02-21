// https://www.acmicpc.net/problem/11098


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

    int n;
    cin >> n;

    while(n--){
        int p;
        cin >> p;
        string ans;
        int mx = 0;
        while(p--){
            int c;
            string name;
            cin >> c >> name;
            if(mx < c) {
                ans = name;
                mx = c;
            }
        }
        cout << ans << el;
    }
    
   
    return 0;
}
