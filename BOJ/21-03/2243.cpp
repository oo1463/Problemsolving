// https://www.acmicpc.net/problem/2243

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int tree[3004002];
int arr[1000001];

// 세그먼트트리 초기화
int init(int start, int end, int node){
    if(start == end) return tree[node] = arr[start]; // 만약 원소가 하나인 경우 tree[node]는 해당 배열의 원소

    int mid = (start + end) / 2;

    // 해당 노드는 왼쪽 자식의 노드 + 오른쪽 자식의 노드
    return tree[node] = init(start,mid, node*2) + init(mid+1 , end, node*2 + 1);
}

int sum(int start, int end, int node, int target){ 
    if(start == end) return start;
    int mid = (start + end) / 2;
    if(target <= tree[node*2]) return sum(start, mid, node*2, target);
    else return sum(mid+1, end, node*2+1, target - tree[node*2]);
    
}

void update(int start, int end, int node, int index, int diff){
    if(index < start || index > end) return;

    tree[node] += diff;
    if(start == end) return;
    int mid = (start + end) / 2;

    update(start, mid, node*2, index, diff);
    update(mid+1, end, node*2+1, index, diff);
    
}

int main() {
    FAIO;
    int n; cin >> n;

    init(1,n, 1);

    while(n--){
        int a,b,c;
        
        cin >> a >> b;

        if(a == 1){
            int num = sum(1,1000001,1,b);
            cout << num << el;
            update(1,1000001,1,num,-1);
        }

        if(a == 2) {
            cin >> c;
            if(arr[b] + c < 0) {
                update(1,1000001,1,b,-arr[b]);
                arr[b] = 0;
            }
            else{
                update(1,1000001,1,b,c);
                arr[b] += c;
            }
            
        }

        
    }
   
    return 0;
}



/*
    Algorithm : segtree, binary search

    Time complexity : O(nlogn)
    
*/
