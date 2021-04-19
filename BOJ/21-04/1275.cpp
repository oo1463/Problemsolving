// https://www.acmicpc.net/problem/1275

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

long long tree[304002];
long long arr[100001];

// 세그먼트트리 초기화
long long init(int start, int end, int node){
    if(start == end) return tree[node] = arr[start]; // 만약 원소가 하나인 경우 tree[node]는 해당 배열의 원소

    int mid = (start + end) / 2;

    // 해당 노드는 왼쪽 자식의 노드 + 오른쪽 자식의 노드
    return tree[node] = init(start,mid, node*2) + init(mid+1 , end, node*2 + 1);
}

long long sum(int start, int end, int node, int left, int right){ 
    // 범위 밖에 있는 경우
    if(left > end || right < start) return 0;

    if(left <= start && right >= end) return tree[node];

    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node*2 + 1, left, right);
}

// index : 수정하고자 하는 노드의 index, diff : 해당 값에 더하고자 하는 값
void update(int start, int end, int node, int index, long long diff){
    if(index < start || index > end) return;

    tree[node] += diff;
    if(start == end) {
        arr[start] = arr[start] + diff;
        return;
    }
    int mid = (start + end) / 2;

    update(start, mid, node*2, index, diff);
    update(mid+1, end, node*2+1, index, diff);
    
}

int main() {
    FAIO;
    int n, q;
    cin >> n >> q;    
    for(int i=1; i<=n; i++) cin >> arr[i];

    init(1,n,1);

    for(int i=0; i<q; i++){
        int x,y,a;
        long long b;
        cin >> x >> y >> a >> b;
        if(x<y) cout << sum(1,n,1,x,y) << el;
        else cout << sum(1,n,1,y,x) << el;
                
        update(1,n,1,a, b-arr[a]);
        
    }
   
    return 0;
}


/*
    Algorithm : segtree

    Time complexity : O(NlogN)
    
*/
