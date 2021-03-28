// https://www.acmicpc.net/problem/14226

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

queue<pair<int,int>> q;
queue<int> timeQ;
bool visited[5002][5002];
int s;

int bfs(pair<int,int> start){
    q.push(start);
    timeQ.push(0);
    visited[start.first][start.second] = true;

    while(!q.empty()){
        pair<int,int> tmp = q.front();
        int time = timeQ.front();
        timeQ.pop();
        q.pop();

        // cout << tmp.first << ' ' << tmp.second << ' ' << time << el;
        if(tmp.first == s){        
            return time;
        }

        int i1 = tmp.first + tmp.second;
        int i2 = tmp.second;

        if(!visited[i1][i2] && i1 >= 0 && i2 >= 0 && i1 <= 2001){
            visited[i1][i2] = true;
            q.push({i1,i2});
            timeQ.push(time+1);
        }

        i1 = tmp.first;
        i2 = tmp.first;

        if(!visited[i1][i2] && i1 >= 0 && i2 >= 0 && i1 <= 2001){
            visited[i1][i2] = true;
            q.push({i1,i2});
            timeQ.push(time+1);
        }

        i1 = tmp.first - 1;
        i2 = tmp.second;

        if(!visited[i1][i2] && i1 >= 0 && i2 >= 0 && i1 <= 2001){
            visited[i1][i2] = true;
            q.push({i1, i2});
            timeQ.push(time+1);
        }
    }
}

int main() {
    FAIO;
    cin >> s;

    cout << bfs({1,0});
   
    return 0;
}



/*
    Algorithm : bfs, dp

    Time complexity : O(N^2)
    
*/
