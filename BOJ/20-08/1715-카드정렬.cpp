// https://www.acmicpc.net/problem/1715

//시간제한  메모리
//2 초	128 MB

#include <iostream>
#include <queue>

#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int> > pq;

int main() {
    FAIO;
    int tmp;
    int t;
    int first, second , sum = 0;

    cin >> N;
    t = N;

    while (t--) {
        cin >> tmp;
        pq.push(tmp);
    }
    
    while (pq.size() > 1) {
        first = pq.top();
        pq.pop();
        second = pq.top();
        pq.pop();
        sum += first + second;
        pq.push(first + second);
    }

    cout << sum;

    return 0;
}


/*
    Algorithm : Heap (priority queue)

    Time complexity : O(NlogN)

*/