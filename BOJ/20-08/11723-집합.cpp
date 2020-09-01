// https://www.acmicpc.net/problem/11723

//시간제한  메모리
//1.5 초	4 MB

#include <iostream>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int M;
bool num[21];

void add(int x) {
    num[x] = true;
}

void remove(int x) {
    num[x] = false;
}

void check(int x) {
    if (num[x]) cout << 1 << el;
    else cout << 0 << el;
}

void toggle(int x) {
    if (num[x]) num[x] = false;
    else num[x] = true;
}

void all() {    
    memset(num, true, sizeof(num));
}

void empty() {
    memset(num, false, sizeof(num));

}

int main() {
    FAIO;

    string s;
    int x;

    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> s;

        if (s == "add") {
            cin >> x;
            add(x);
        }
        else if (s == "check") {
            cin >> x;
            check(x);
        }
        else if (s == "remove") {
            cin >> x;
            remove(x);
        }
        else if (s == "toggle") {
            cin >> x;
            toggle(x);
        }
        else if (s == "all") all();
        else if (s == "empty") empty();
    }



    return 0;
}


/*
    Algorithm : 

    Time complexity : O(M)

*/