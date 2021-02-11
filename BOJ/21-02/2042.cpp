// https://www.acmicpc.net/problem/2042

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

// 세그먼트 트리의 크기는 배열의 크기보다 큰 가장 가까운 N의 제곱수를 구하고 그것의 2배이다.
// ex. N == 100000 일 때 
// 트리의 크기 : 102001*2 = 204002
long long tree[3*1000001];
long long arr[1000001];

// 세그먼트트리 초기화
long long init(long long start, long long end, long long node){
    if(start == end) return tree[node] = arr[start]; // 만약 원소가 하나인 경우 tree[node]는 해당 배열의 원소

    long long mid = (start + end) / 2;

    // 해당 노드는 왼쪽 자식의 노드 + 오른쪽 자식의 노드
    return tree[node] = init(start,mid, node*2) + init(mid+1 , end, node*2 + 1);
}

long long sum(long long start, long long end, long long node, long long left, long long right){ 
    // 범위 밖에 있는 경우
    if(left > end || right < start) return 0;

    if(left <= start && right >= end) return tree[node];

    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node*2 + 1, left, right);
}

// index : 수정하고자 하는 노드의 index, diff : 해당 값에 더하고자 하는 값
void update(long long start, long long end, long long node, long long index, long long diff){
    if(index < start || index > end) return;

    tree[node] += diff;
    if(start == end) {
        arr[start] += diff;
        return;
    }
    long long mid = (start + end) / 2;

    update(start, mid, node*2, index, diff);
    update(mid+1, end, node*2+1, index, diff);
    
}

long long N, M, K;

int main() {
    FAIO;
    
    cin >> N >> M >> K;
    for(long long i=1; i<=N; i++) cin >> arr[i];
    init(1, N, 1);
    for(long long i=0; i<M + K; i++) {
        long long what, where, how;
        cin >> what >> where >> how;
        if(what == 1){
            update(1, N, 1, where, how-arr[where]);
        }
        else if(what == 2){
            cout << sum(1, N, 1, where, how) << el;
        }

    }
   
    return 0;
}


/*
    Algorithm : segment tree

    Time complexity : O(NlogN)
    
*/
