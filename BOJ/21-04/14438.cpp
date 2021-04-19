// https://www.acmicpc.net/problem/14438

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int tree[304002];
int arr[100001];

// 세그먼트트리 초기화
int init(int start, int end, int node){    
    if(start == end) return tree[node] = arr[start]; // 만약 원소가 하나인 경우 tree[node]는 해당 배열의 원소
    
    int mid = (start + end) / 2;

    // 해당 노드는 왼쪽 자식의 노드 , 오른쪽 자식의 노드 중 작은 값
    int l = init(start, mid, node * 2);
    int r = init(mid + 1, end, node*2 + 1);
    tree[node] = r > l ? l : r;
    return tree[node];
}

int query(int start, int end, int node, int left, int right){ 
    // 범위 밖에 있는 경우
    if(left > end || right < start) return tree[node];

    if(left <= start && right >= end) {
        return tree[node];
    }

    int mid = (start + end) / 2;

    int l = query(start, mid, node * 2, left, right);
    int r = query(mid + 1, end, node*2 + 1, left, right);
    return r > l ? l : r;
}

// index : 수정하고자 하는 노드의 index, changed : 해당 값을 변경하고자 하는 값
int update(int start, int end, int node, int index, int changed){
    if(index < start || index > end) return tree[node];

    if(start == end) {
        arr[start] = changed;
        tree[node] = changed;        
        return tree[node];
    }
    int mid = (start + end) / 2;

    int l = update(start, mid, node*2, index, changed);
    int r = update(mid+1, end, node*2+1, index, changed);
    tree[node] = l < r ? l : r;
    return tree[node];
}

int main() {
    FAIO;
    int n, M;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> arr[i];

    init(1,n,1);

    cin >> M;
    for(int i=0; i<M; i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a == 1) update(1,n,1, b, c);
        else cout << query(1,n,1,b,c) << el;
    }
    
    return 0;
}


/*
    Algorithm : segtree

    Time complexity : O(NlogN)
    
*/
