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
long long tree[4040020];
long long arr[1000001];

// 세그먼트트리 초기화
long long init(int start, int end, int node){
    if(start == end) return tree[node] = arr[start]; // 만약 원소가 하나인 경우 tree[node]는 해당 배열의 원소

    int mid = (start + end) / 2;

    // 해당 노드는 왼쪽 자식의 노드 + 오른쪽 자식의 노드
    return tree[node] = (init(start,mid, node*2) * init(mid+1 , end, node*2 + 1)) % 1000000007;
}

long long mult(int start, int end, int node, int left, int right){ 
    // 범위 밖에 있는 경우
    if(left > end || right < start) return 1;

    if(left <= start && right >= end) return tree[node];

    int mid = (start + end) / 2;
    return (mult(start, mid, node * 2, left, right) * mult(mid + 1, end, node*2 + 1, left, right)) % 1000000007;
}

// index : 수정하고자 하는 노드의 index, diff : 해당 값으로 바꾸자 하는 값
long long update(int start, int end, int node, int index, long long diff){
    
    if(index < start || index > end) return tree[node];    
    
    if(start == end) {        
        return tree[node] = diff;
    }
    int mid = (start + end) / 2;

    // cout << tree[node] << ' ' << start << ' ' << end << ' ' << mid << el;

    return tree[node] = (update(start, mid, node*2, index, diff) * update(mid+1, end, node*2+1, index, diff)) % 1000000007;
    
}

int main() {
    FAIO;

    int N,M,K;
    
    cin >> N >> M >> K;
    

    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }    

    init(1,N,1);

    for(int i=0; i<M+K; i++){
        int a,b;
        long long c;
        cin >> a >> b >> c;
        
        if(a == 1){            
            update(1, N, 1, b, c);            
        }
        else{
            cout << mult(1,N,1,b,c) % 1000000007 << el;
        }
    }
    
    return 0;
}



/*
    Algorithm : segment tree

    Time complexity : O(NlogN)
    
*/
