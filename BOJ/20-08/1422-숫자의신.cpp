// https://www.acmicpc.net/problem/1422

//시간제한  메모리
//2 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, K;
vector<int> num;

bool cmp(int a, int b) { return to_string(a) + to_string(b) > to_string(b) + to_string(a); }

int main() {
    FAIO;
    int maxx = 0;
    int tmp;

    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        cin >> tmp;      
        num.push_back(tmp);
        if (maxx < tmp) maxx = tmp;
    }

    for (int i = 0; i < N - K; i++) num.push_back(maxx);
    sort(num.begin(), num.end(), cmp);

    for (auto i = num.begin(); i != num.end(); i++) cout << *i;

    return 0;
}

/*
    Algorithm : sort

    Time complexity : O(NlogN)

*/