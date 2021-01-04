#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int draw_card[5];
int cnt_card[14];
map<int, int> m;

// void backtracking(int si, int di){
//     if(si == 5){
//         for(int i=1; i<=13; i++){

//         }
//         for(int i=0; i<5; i++) cout << draw_card[i] << ' ';
//         cout << el;
//         return;
//     }
// }


int main() {
    FAIO;

    int one = 0; 
    int two = 0;

    for(int a=1; a<=13; a++){
        m[a]++;
        for(int b=a; b<=13; b++){
            m[b]++;
            for(int c=b; c<=13; c++){
                m[c]++;
                for(int d=c; d<=13; d++){
                    m[d]++;
                    for(int e=d; e<=13; e++){
                        m[e]++;
                        for(auto x : m){
                            if(x.second == 1) one++;
                            else if(x.second == 2) two++;
                        }
                        if(one == 3 && two == 1){
                            cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << el;
                        }
                        one = 0;
                        two = 0;
                        m[e]--;
                    }
                    m[d]--;
                }
                m[c]--;
            }
            m[b]--;
        }
        m[a]--;
    }
   
    return 0;
}