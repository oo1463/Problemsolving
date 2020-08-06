// https://www.acmicpc.net/problem/1107

//시간제한  메모리
//2 초	256 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, M;
int arr[100];
vector<int> v;
int num;
int mina;

void dfs(int arri) {
    if (arri == 6) {            
        return;
    }

    for (int i = 0; i < 10-M; i++) {
        arr[arri] = v[i];

        num = 0;
        for (int i = 0; i <= arri; i++) {
            num = num + arr[i] * pow(10,arri-i);
        }

        if (abs(N - num) + arri + 1 < mina) {
            mina = abs(N - num) + arri + 1;      
        }

        dfs(arri + 1);
    }
}

int main() {
    FAIO;
    
    int tmp;

    cin >> N;
    cin >> M;        

    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    for (int i = 0; i < M; i++) {
        cin >> tmp;
        v.erase(find(v.begin(), v.end(), tmp));
    }

    mina = abs(N - 100);

    dfs(0);

    cout << mina;
    return 0;
}


/*
    Algorithm : DFS (backtracking)

    Time complexity : O((10-M)^6) -> O(M^6)

*/