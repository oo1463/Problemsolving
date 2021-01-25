// https://www.acmicpc.net/problem/2578

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int bingo_pan[5][5];
bool checked[5][5];
bool bingoX[5];
bool bingoY[5];
bool bingoCross[2];
int cnt_bingo = 0;

bool checkX(int x){
    for(int i=0; i<5; i++){
        if(checked[x][i] == false) return false;
    }
    return true;
}

bool checkY(int y){
    for(int i=0; i<5; i++){
        if(checked[i][y] == false) return false;
    }
    return true;
}

bool checkDiagonal1(int x, int y){ // x == y
    for(int i=0; i<5; i++){
        if(checked[i][i] == false) return false;
    }
    return true;
}

bool checkDiagonal2(int x, int y){ // x + y = 4
    for(int i=0; i<5; i++){
        if(checked[4-i][i] == false) return false;
    }
    return true;
}

void print_check(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++) cout << checked[i][j] << ' ';
        cout << el;
    }
    cout << el;
}

int main() {
    FAIO;
    
    int check;
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++) cin >> bingo_pan[i][j];
    }
    int cnt = 0;
    bool flag_cnt = false;
    int answer = 0;

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++) {
            cnt++;
            cin >> check;
            int wherei, wherej;
            bool flag = 0;
            for(int k=0; k<5; k++){
                for(int l=0; l<5; l++){
                    if(bingo_pan[k][l] == check){
                        wherei = k;
                        wherej = l;
                        flag = 1;
                        break;
                    }
                    if(flag == 1) break;
                }
            }
            
            checked[wherei][wherej] = true;
            // print_check();
            if(checkX(wherei)) {
                bingoX[wherei] = true;
                cnt_bingo++;
            }
            if(checkY(wherej)) {
                bingoY[wherej] = true;
                cnt_bingo++;
            }

            if(wherei == wherej && checkDiagonal1(wherei, wherej)) {
                bingoCross[0] = true;
                cnt_bingo++;
            }
            if(wherei + wherej == 4 && checkDiagonal2(wherei, wherej)) {
                bingoCross[1] = true;
                cnt_bingo++;
            }

            if(!flag_cnt && cnt_bingo >= 3) {
                answer = cnt;
                flag_cnt = true;
            }
        }
    }

    cout << answer;

    return 0;
}



/*
    Algorithm : implementationm , simultation

    Time complexity : O(1)
    
*/
