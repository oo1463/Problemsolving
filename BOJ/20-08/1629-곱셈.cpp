// https://www.acmicpc.net/problem/1629

//시간제한  메모리
//2 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int main() {
    FAIO;

    long long C;
    long long e,num, tmp = 1, ans;

    cin >> num >> e >> C;

    while (e > 1) {

        if (e % 2 == 0) {
            num = (num * num) % C;
            e = e / 2;
        }
        else {
            tmp = (tmp * num) % C;
            num = (num * num) % C;
            e = (e - 1) / 2;
        }
        //cout << num << '^' << e << '*' << tmp << el;

    }

    ans = (num * tmp) % C;
    cout << ans;

    return 0;
}


/*
    Algorithm : divide & conquer

    Time complexity : O(loge)

*/