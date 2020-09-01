// https://www.acmicpc.net/problem/1927

//시간제한  메모리
//1 초 (추가 시간 없음)	128 MB

#include <iostream>
#include <vector>
#include <queue>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

void add(int x) {
    pq.push(x);
}

void del() {
    if (!pq.empty()) {
        cout << pq.top() << el;
        pq.pop();
    }
    else cout << '0' << el;
}

int main() {
    FAIO;

    int N;
    int x;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x == 0) del();
        else add(x);
    }

    return 0;
}


/*
    Algorithm : Heap

    Time complexity : O(NlogN)

*/