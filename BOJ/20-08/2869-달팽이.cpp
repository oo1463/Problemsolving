// https://www.acmicpc.net/problem/2869

//시간제한  메모리
//0.15 초 (추가 시간 없음)	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;



int main() {
    FAIO;

    int A, B , V;

    cin >> A >> B >> V;
    

    if ((V - A) % (A - B) == 0) cout << (V - A) / (A - B) + 1;
    else cout << (V - A) / (A - B) + 2;
    

    return 0;
}


/*
    Algorithm : 

    Time complexity : O(C)

*/