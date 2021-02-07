// https://www.acmicpc.net/problem/7578

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
    long long value, lazy; 
} Tree;

Tree tree[3*1000010];

int arr[500001];
int m[1000001];

void update_range(int node, int start, int end, int i, int j, long long diff){ 
    //lazy가 남아있을 때 
    if(tree[node].lazy != 0){ 
        tree[node].value += (end-start+1)*tree[node].lazy; 
        if(start != end){ 
            tree[node*2].lazy += tree[node].lazy; 
            tree[node*2+1].lazy += tree[node].lazy; 
        } 
        tree[node].lazy =0; 
    } 
    if(j < start || i > end) return; //대표 구간을 찾았을 때 
    if(i <= start && end <= j){ 
        tree[node].value += (end-start+1)*diff; 
        if(start != end){ 
            tree[node*2].lazy += diff; 
            tree[node*2+1].lazy += diff; 
        } 
        return; 
    } 
    update_range(node*2, start, (start+end)/2, i, j, diff); 
    update_range(node*2+1, (start+end)/2+1, end, i, j, diff); 
    tree[node].value = tree[node*2].value+tree[node*2+1].value; 
}


long long init(int node, int start, int end){ 
    if(start == end) return tree[node].value = arr[start]; 
    else return tree[node].value = init(node*2, start, (start+end)/2) + init(node*2+1, (start+end)/2+1, end); 
}

long long sum(int node, int start, int end, int i, int j){ 
    if(tree[node].lazy != 0){ 
        tree[node].value += (end-start+1)*tree[node].lazy; 
        if(start != end){ 
            tree[node*2].lazy += tree[node].lazy; 
            tree[node*2+1].lazy += tree[node].lazy; 
        } tree[node].lazy =0; 
    } 
    if(i> end || j < start) return 0; 

    if(i <= start && end <= j) return tree[node].value; 
    return sum(node*2, start, (start+end)/2, i, j)+sum(node*2+1, (start+end)/2+1, end, i, j); 
}


int main() {
    FAIO;

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        m[tmp] = i;
        arr[i] = i;
    }

    init(1, 0, n-1);

    long long cnt = 0;

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        cnt += sum(1, 0, n-1, m[tmp], m[tmp]);
        update_range(1, 0, n-1, m[tmp], n-1 , -1);
    }

    cout << cnt;
   
    return 0;
}


/*
    Algorithm : Segment Tree

    Time complexity : O(NlogN)
    
*/
