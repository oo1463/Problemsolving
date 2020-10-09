// https://www.acmicpc.net/problem/19944

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, M;

int main() {
    FAIO;

    cin >> N >> M;
    if (M < 3) cout << "NEWBIE!";
    else if (M <= N) cout << "OLDBIE!";
    else cout << "TLE!";


    return 0;
}

