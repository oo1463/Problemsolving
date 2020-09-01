// https://www.acmicpc.net/problem/1992

//시간제한  메모리
//2 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int mo[65][65];
int N;
string s[65];

string check(int x, int y, int n) {
    
    if (n == 1) return to_string(mo[x][y]);

    string tmp;

    string wn = check(x - n / 2, y - n / 2, n / 2);
    string ne = check(x - n / 2, y, n / 2);
    string ws = check(x, y - n / 2, n / 2);
    string se = check(x, y, n / 2);


    if ((wn == "0" && ne == "0" && ws == "0" && se == "0"))     tmp += "0";    
    else if (wn == "1" && ne == "1" && ws == "1" && se == "1")  tmp += "1";            
    else tmp += "(" + wn + ne + ws + se + ")";
        
    return tmp;
}

int main() {
    FAIO;

    cin >> N;

    for (int i = 1; i <= N; i++) {
            cin >> s[i];
            for (int j = 1; j <= N; j++) {
                mo[i][j] = s[i][j - 1] - 48;
            }
    }

    cout << check(N, N, N);

    return 0;
}


/*
    Algorithm : divide & conquer

    Time complexity : O(log4(N^2))

*/