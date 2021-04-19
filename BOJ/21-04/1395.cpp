// https://www.acmicpc.net/problem/1395

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>

#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

typedef struct Tree{ 
    int value;
    bool lazy; 
} Tree;

Tree tree[420010];

int arr[100001];

void update_range(int node, int start, int end, int i, int j){ 
    //lazy가 남아있을 때 
    if(tree[node].lazy){ 
        tree[node].value = (end-start+1) - tree[node].value; 
        if(start != end){ 
            tree[node*2].lazy = !tree[node*2].lazy; 
            tree[node*2+1].lazy = !tree[node*2+1].lazy; 
        } 
        tree[node].lazy = false; 
    } 
    if(j < start || i > end) return; //대표 구간을 찾았을 때 
    if(i <= start && end <= j){ 
        tree[node].value = (end-start+1) - tree[node].value; 
        if(start != end){ 
            tree[node*2].lazy = !tree[node*2].lazy; 
            tree[node*2+1].lazy = !tree[node*2+1].lazy; 
        } 
        return; 
    } 
    update_range(node*2, start, (start+end)/2, i, j); 
    update_range(node*2+1, (start+end)/2+1, end, i, j); 
    tree[node].value = tree[node*2].value+tree[node*2+1].value; 
}


int init(int node, int start, int end){ 
    if(start == end) return tree[node].value = arr[start]; 
    else return tree[node].value = init(node*2, start, (start+end)/2) + init(node*2+1, (start+end)/2+1, end); 
}

int sum(int node, int start, int end, int i, int j){ 
    if(tree[node].lazy){ 
        tree[node].value = (end-start+1) - tree[node].value; 
        if(start != end){ 
            tree[node*2].lazy = !tree[node*2].lazy; 
            tree[node*2+1].lazy = !tree[node*2+1].lazy; 
        } 
        tree[node].lazy = false; 
    } 
    if(i > end || j < start) return 0; 

    if(i <= start && end <= j) return tree[node].value; 
    return sum(node*2, start, (start+end)/2, i, j) + sum(node*2+1, (start+end)/2+1, end, i, j); 
}


int main() {
    FAIO;

    int n,m,k;
    cin >> n >> m;

    init(1, 1, n);

    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;

        if(a == 0){
            update_range(1,1,n,b,c);
        }
        else{
            cout << sum(1,1,n,b,c) << el;
        }
    }
    // cout << el;
    // cout << sum(1,1,n,1,n) << " ";
   
    return 0;
}


/*
    Algorithm : Lazy Segment Tree

    Time complexity : O(NlogN)
    
*/
