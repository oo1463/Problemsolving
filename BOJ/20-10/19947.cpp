// https://www.acmicpc.net/problem/19947

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int H, Y;

int getmx(int a, int b) { return a > b ? a : b; }


int main() {
    FAIO;

    cin >> H >> Y;    

    if (Y / 5 > 1) {
        H = H * 1.35;
        Y = Y % 5;
        if (Y / 3 > 1) {
            H = H * 1.2;
            H = H * 1.05 * (Y % 3);
        }
    }
    cout << H;


    return 0;
}
