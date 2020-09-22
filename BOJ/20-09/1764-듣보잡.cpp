// https://www.acmicpc.net/problem/1764

//시간제한  메모리
//2 초	256 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

map<string, int> m;
int N, M;
vector<string> v;

int main() {
    FAIO;

    cin >> N >> M;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        m[s]++;
    }
    for (int j = 0; j < M; j++) {
        string s;
        cin >> s;
        m[s]++;
    }
    for (auto a : m) {
        if (a.second >= 2) {
            sum++;
            v.push_back(a.first);
        }
    }

    sort(v.begin(), v.end());

    for (auto a : v) cout << a << el;

    return 0;
}


/*
    Algorithm :

    Time complexity : O(N^2)

*/