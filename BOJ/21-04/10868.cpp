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
pair<int,int> tree[304002];
int arr[100001];

// 세그먼트트리 초기화
pair<int,int> init(int start, int end, int node){
    if(start == end) {
        tree[node].first = arr[start];
        tree[node].second = arr[start];
        // cout << tree[node].first << ' ' << tree[node].second  << ' ' << start << el;
        return tree[node];
    }
    int mid = (start + end) / 2;

    // 해당 노드는 왼쪽 자식의 노드 + 오른쪽 자식의 노드

    pair<int,int> left = init(start,mid, node*2);
    pair<int,int> right = init(mid+1 , end, node*2+1);
    int left_mx = left.first;
    int right_mx = right.first;
    int left_mn = left.second;
    int right_mn = right.second;
    tree[node].first = left_mx > right_mx ? left_mx : right_mx;
    tree[node].second = left_mn > right_mn ? right_mn : left_mn;

    return tree[node];
}

pair<int,int> sum(int start, int end, int node, int left, int right){ 
    // 범위 밖에 있는 경우
    if(left > end || right < start) return {0,1000000001};

    if(left <= start && right >= end) return tree[node];

    int mid = (start + end) / 2;

    pair<int,int> l = sum(start, mid, node * 2, left, right);
    pair<int,int> r = sum(mid + 1, end, node*2 + 1, left, right);
    int left_mx = l.first;
    int right_mx = r.first;
    int left_mn = l.second;
    int right_mn = r.second;
    int a = right_mx > left_mx ? right_mx : left_mx;
    int b = right_mn > left_mn ? left_mn : right_mn;

    pair<int, int> t = {a,b};

    return t;
}


int main() {
    FAIO;
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    init(1,n,1);
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        pair<int,int> t = sum(1,n,1,a,b);
        cout << t.second << el;
    }
    
    return 0;
}


/*
    Algorithm : segtree

    Time complexity : O(NlogN)
    
*/
