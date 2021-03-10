// https://www.acmicpc.net/problem/14427

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
pair<int,int> tree[3*102001];
int arr[100001];

pair<int,int> lesser(pair<int,int> a, pair<int,int> b) {
        if(a.second > b.second) return b;
        else if(a.second == b.second) {
            return a.first < b.first ? a:b;
        }
        return a;
    }

// 세그먼트트리 초기화
pair<int,int> query(int start, int end, int node){
    if(start == end) {
        tree[node].first = start;      
        tree[node].second = arr[start];  
        return tree[node]; // 만약 원소가 하나인 경우 tree[node]는 해당 배열의 원소
    }

    int mid = (start + end) / 2;

    // 해당 노드는 왼쪽 자식의 노드 + 오른쪽 자식의 노드
    
    return tree[node] = lesser(query(start,mid, node*2), query(mid+1 , end, node*2 + 1));
}

// index : 수정하고자 하는 노드의 index, diff : 해당 값에 더하고자 하는 값
pair<int,int> update(int start, int end, int node, int index, int diff){
    if(index < start || index > end) return tree[node];

    if(start == end) {
        arr[start] = diff;
        tree[node].second = diff;
        tree[node].first = start;
        return tree[node];
    }
    int mid = (start + end) / 2;

    return tree[node] = lesser(update(start, mid, node*2, index, diff), update(mid+1, end, node*2+1, index, diff));
}

int main() {
    FAIO;
    
    int N, M;
    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];

    cin >> M;

    query(1,N,1);

    for(int i=0; i<M; i++){
        int a,b,c;
        cin >> a;
        if(a==2){
            cout << tree[1].first << el;
        }
        else{
            cin >> b >> c;
            update(1,N,1,b,c);
        }
    }    

    return 0;
}


/*
    Algorithm : segtree

    Time complexity : O(NlogN)
    
*/
