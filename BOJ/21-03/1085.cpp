// https://www.acmicpc.net/problem/1085

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int minn(int a, int b) {
    return a<b?a:b;
}

int main() {
    FAIO;
    int x,y,w,h;
    cin >> x >> y >> w >> h;

    int ans = minn(minn(x,abs(x-w)),minn(y,abs(y-h)));
    
    cout << ans;
    return 0;
}
