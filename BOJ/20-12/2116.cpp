// https://www.acmicpc.net/problem/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N;
int dice[10001][6];
int m[6];
int sum;
int sum_max;

void stack_on(int bottom_value,  int dice_index){
    if(dice_index > N-1) {
        if(sum > sum_max) sum_max = sum;
        sum = 0;
        return;
    }

    int bottom_index;
    
    for(int i=0; i<6; i++){
        if(bottom_value == dice[dice_index][i]){
            bottom_index = i;
            break;
        }
    }
    int top_index = m[bottom_index];
    int top_value = dice[dice_index][top_index];
    
    if(bottom_value == 6){
        if(top_value == 5) sum+=4;
        else
            sum += 5;
    }
    else if(bottom_value == 5){
        if(top_value == 6) sum += 4;
        else
            sum += 6;
    }
    else {
        if(top_value == 6) sum += 5;
        else
            sum += 6;
    }

    stack_on(top_value, dice_index+1);
}

int main() {
    FAIO;
    
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<6; j++){
            cin >> dice[i][j];
        }        
    }

    m[0] = 5;
    m[1] = 3;
    m[2] = 4;
    m[3] = 1;
    m[4] = 2;
    m[5] = 0;

    int result[6];

    for(int i=1 ; i<=6; i++){
        stack_on(i, 0);
    }
    
    cout << sum_max;

   
    return 0;
}



/*
    Algorithm : implementation

    Time complexity : O(N)
    
*/
