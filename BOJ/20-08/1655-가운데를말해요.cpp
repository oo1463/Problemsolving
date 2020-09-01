// https://www.acmicpc.net/problem/1655

//시간제한  메모리
//2 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;


int N;
priority_queue<int, vector<int>, greater<int> > pq;
priority_queue<int, vector<int>, less<int> > lpq;



int main() {
    FAIO;

	int tmp;
	cin >> N;
	for(int i=1; i<=N; i++){
		cin >> tmp;
		if (i % 2 == 1) lpq.push(tmp);
		else pq.push(tmp);
		
		if(pq.empty()) cout << lpq.top() << el;
		else if (lpq.top() > pq.top()) {
			int tmpa, tmpb;
			tmpa = lpq.top();
			tmpb = pq.top();
			lpq.pop();
			pq.pop();
			lpq.push(tmpb);
			pq.push(tmpa);
			cout << lpq.top() << el;
		}
		else {
			cout << lpq.top() << el;
		}		
	}
	
    return 0;
}


/*
    Algorithm : Heap

    Time complexity : O(NlogN)

*/