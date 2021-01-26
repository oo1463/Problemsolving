// https://www.acmicpc.net/problem/1092

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <list>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N,M;
vector<int> crain;
list<int> box;

int main() {
    FAIO;

    cin >> N;
    
    while(N--) {
        int tmp;
        cin >> tmp;
        crain.push_back(tmp);        
    }

    cin >> M;

    while(M--){
        int tmp;
        cin >> tmp;
        box.push_back(tmp);
    }

    int sz = crain.size();
    sort(crain.begin(), crain.end(), greater<int>());
    box.sort(greater<int>());

    if(crain.front() < box.front()) {
        cout << -1;
        return 0;
    }
    int cnt = 0;

    while(!box.empty()){
        int i=0;
        for(auto a = box.begin(); a != box.end();){
            if(crain[i] >= *a){
                i++;
                a = box.erase(a);
                if(i == sz) break;
            }
            else a++;
        }
        cnt++;
    }

    cout << cnt;

    return 0;
}



/*
    Algorithm : list

    Time complexity : O(NlogN)
    
*/
