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
    if(sqrt(n) == (int) sqrt(n)) return true;

    return false;
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
            
            for(int x=-N; x<=N; x++){
                for(int y=-M; y<=M; y++){
                    string tmp_making = ts;
                    // tmp_making += map[i][j];
                    if(x==0 && y == 0) continue;

                    for(int mult=1; mult<=8; mult++){
                        int new_x = i + x*mult;
                        int new_y = j + y*mult;
                        if(new_x >= 0 && new_x < N && new_y >= 0 && new_y < M){
                            tmp_making += map[new_x][new_y];
                            // cout << tmp_making << el;
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
    Algorithm : BruteForce

    Time complexity : O(N^5)
    
*/
