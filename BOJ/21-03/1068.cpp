// https://www.acmicpc.net/problem/1068

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N;
vector<int> v[50];
int cnt;

void dfs(int start){
    if(v[start].size() == 0) {
        cnt++;
        return;
    }

    for(int i=0; i<v[start].size(); i++){
        dfs(v[start][i]);
    }
}

int main() {
    FAIO;

    cin >> N;

    int node[50];
    int root;

    for(int i=0; i<N; i++){
        cin >> node[i];
        if(node[i] == -1) root = i;
    }

    int del;

    cin >> del;

    if(root == del){
        cout << 0;
        return 0;
    }

    for(int i=0; i<N; i++){
        if(i != del && node[i] != del){
            v[node[i]].push_back(i);
        }
    }

    dfs(root);

    cout << cnt;
   
    return 0;
}


/*
    Algorithm : tree DFS

    Time complexity : O(N)
    
*/
