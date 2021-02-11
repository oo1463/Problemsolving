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
int tree[1000000];
int arr[500000];

int init(int start, int end, int node){
    if(start == end) return tree[node] = arr[start]; // 만약 원소가 하나인 경우 tree[node]는 해당 배열의 원소

    int mid = (start + end) / 2;

    // 해당 노드는 왼쪽 자식의 노드 + 오른쪽 자식의 노드
    return tree[node] = init(start,mid, node*2) + init(mid+1 , end, node*2 + 1);
}



int main() {
    FAIO;
    
   
    return 0;
}



/*
    Algorithm : 

    Time complexity : O(N^2)
    
*/
