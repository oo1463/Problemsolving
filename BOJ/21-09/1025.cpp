// https://www.acmicpc.net/problem/1025

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N,M;
char map[10][10];

bool is_square(string s){
    int n = stoi(s);
    if(sqrt(n)*sqrt(n) == n) return true;

    return false;
}

string reverse(string s){
    for(int i=0; i<s.size()/2; i++){
        swap(s[i], s[s.size() - i - 1]);
    }

    return s;
}

int main() {
    FAIO;

    cin >> N >> M;
    for(int i=0; i<N; i++){
        string ts;
        cin >> ts;
        for(int j=0; j<M; j++){
            map[i][j] = ts[j];
        }
    }

    
    int mx = -1;

   

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            string ts;
            ts += map[i][j];
            if(is_square(ts) && stoi(ts) > mx){
                mx = stoi(ts);
            }
            
            for(int x=-9; x<=9; x++){
                for(int y=-9; y<=9; y++){
                    string tmp_making;
                    tmp_making += map[i][j];
                    if(x==0 && y==0) continue;

                    for(int mult=1; mult<=8; mult++){
                        if((i+x*mult) >= 0 && (i+x*mult) <N && (j+y*mult) >=0 && (j+y*mult)<M){
                            tmp_making += map[(i+x*mult)][(j+y*mult)];
                            if(is_square(tmp_making) && stoi(tmp_making) > mx){
                                mx = stoi(tmp_making);
                            }
                        }
                    }
                }
            }
        }
    }

    cout << mx;
   
    return 0;
}


/*
    Algorithm : 

    Time complexity : O(N^2)
    
*/
