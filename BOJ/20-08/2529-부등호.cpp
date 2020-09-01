// https://www.acmicpc.net/problem/2529

//시간 제한	메모리 제한
//1 초	256 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int k;
char d[10];
vector<char> n;
int flag = 0;

bool check(int arri) {
    if (arri > 0) {
        if (d[arri - 1] == '<') {
            if (n[arri - 1] >= n[arri]) {
                n.pop_back();
                return true;
            }
        }
        else if (d[arri - 1] == '>') {
            if (n[arri - 1] <= n[arri]) {
                n.pop_back();
                return true;

            }
        }
    }
    return false;
}

void solve(int arri) {

    if (flag == 1) return;
        
    if (arri == k + 1) {        
        for (int i = 0; i < arri; i++) cout << n[i];
        cout << el;
        flag = 1;
        return;
    }
    
    for (char i = '9'; i >= '0'; i--) {
        
        if (find(n.begin(), n.end(), i) == n.end())
            n.push_back(i);
        else continue;

        if (check(arri)) continue;

        solve(arri + 1);
        n.pop_back();
    }                
}

void solve2(int arri) {

    if (flag == 1) return;

    if (arri == k + 1) {
        for (int i = 0; i < arri; i++) cout << n[i];
        cout << el;
        flag = 1;
        return;
    }

    for (char i = '0'; i <= '9'; i++) {

        if (find(n.begin(), n.end(), i) == n.end())
            n.push_back(i);
        else continue;

        if (check(arri)) continue;

        solve2(arri + 1);
        n.pop_back();
    }
}


int main() {
    FAIO;

    cin >> k;

    for (int i = 0; i < k; i++) cin >> d[i];

    solve(0);
    flag = 0;
    solve2(0);

    return 0;
}


/*
    Algorithm : DFS , backtracking
    Time complexity : O(k!)

*/