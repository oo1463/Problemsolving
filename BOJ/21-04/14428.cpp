// https://www.acmicpc.net/problem/14428

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

pair<int,int> tree[404002];
int arr[100001];

// 세그먼트트리 초기화
pair<int,int> init(int start, int end, int node){    
    if(start == end) {
        tree[node].first = arr[start]; // 만약 원소가 하나인 경우 tree[node]는 해당 배열의 원소
        tree[node].second = start;
        return tree[node];
    }
    
    int mid = (start + end) / 2;

    // 해당 노드는 왼쪽 자식의 노드 , 오른쪽 자식의 노드 중 작은 값
    pair<int,int> l = init(start, mid, node * 2);
    pair<int,int> r = init(mid + 1, end, node*2 + 1);
    if(l.first > r.first){
        tree[node].first = r.first;
        tree[node].second = r.second;
    }
    else{
        tree[node].first = l.first;
        tree[node].second = l.second;
    }
    return tree[node];
}

pair<int,int> query(int start, int end, int node, int left, int right){ 
    // 범위 밖에 있는 경우
    if(left > end || right < start) return {2000000001, start};

    if(left <= start && right >= end) {        
        return tree[node];
    }

    int mid = (start + end) / 2;

    pair<int,int> l = query(start, mid, node * 2, left, right);
    pair<int,int> r = query(mid + 1, end, node*2 + 1, left, right);
    pair<int,int> t;
    if(l.first > r.first){
        t.first = r.first;
        t.second = r.second;
    }
    else{
        t.first = l.first;
        t.second = l.second;
    }
    return t;
}

// index : 수정하고자 하는 노드의 index, changed : 해당 값을 변경하고자 하는 값
pair<int,int> update(int start, int end, int node, int index, int changed){
    if(index < start || index > end) return tree[node];

    if(start == end) {
        arr[start] = changed;
        tree[node].first = changed;        
        tree[node].second = start;
        return tree[node];
    }
    int mid = (start + end) / 2;

    pair<int,int> l = update(start, mid, node*2, index, changed);
    pair<int,int> r = update(mid+1, end, node*2+1, index, changed);

    if(l.first > r.first){
        tree[node].first = r.first;
        tree[node].second = r.second;
    }
    else{
        tree[node].first = l.first;
        tree[node].second = l.second;
    }
    
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
        else cout << query(1,n,1,b,c).second << el;
    }
    
    return 0;
}


/*
    Algorithm : segtree

    Time complexity : O(NlogN)
    
*/
