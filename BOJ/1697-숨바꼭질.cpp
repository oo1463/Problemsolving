// https://www.acmicpc.net/problem/1697

//시간제한  메모리
// 2 초	  128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 100001
using namespace std;

int N, K;
int level;
queue<int> q;
bool a[MAX];

/*void dfs(int x) {
    v.push_back(x);
    if (x == K) {
        countx = v.size()-1;
        minx = get_min(minx, countx);

        //for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
        //cout << ' ' << countx << '\n' << '\n';
        v.pop_back();
        return;
    }
    else if (x > K) {        
        countx = v.size() - 1 + x - K;
        minx = get_min(minx, countx);        
        //for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
        //cout << ' ' << countx << '\n' << '\n';
        v.pop_back();
        return;
    }
    //else if ((x - 1) * 2 > K&& x < K) {        
    //    countx = v.size() - 1 + K - x;
    //    minx = get_min(minx, countx);
    //    for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
    //    cout << ' ' << countx << '\n' << '\n';
    //    v.pop_back();
    //    return;
    //}

    /*if (x > 1) {                
        dfs(x + x);
        if (x > 2) {
            v.push_back(x - 1);
            dfs(x * 2 - 2);
        }                      
    }        
    else     
        dfs(x + 1);
    if (x < 2) dfs(x + 1);
    else if (x == 2) {
        dfs(x + 1);
        dfs(x * 2);
    }
    else if (x*2 <= K) {
        dfs(x * 2);
        v.push_back(x - 1);
        dfs(x * 2 - 2);
    }
    else {
        dfs(x * 2);
        v.push_back(x - 1);
        dfs(x * 2 - 2);
        dfs(x + 1);
    }
         
    v.pop_back();
}*/

void bfs(int x) {
    int seg = 1;
    int cnt = 0;

    q.push(x);
    level = 0;
    a[x] = true;

    while (1) {
        for (int i = 0; i < seg; i++) {            
            x = q.front();            
            q.pop();
            if (x == K) return;

            if (2 * x < MAX && a[2 * x] == false) {
                q.push(2 * x);
                a[2 * x] = true;
                cnt++;
            }

            if (x + 1 < MAX && a[x + 1] == false) {
                q.push(x + 1);
                a[x + 1] = true;
                cnt++;
            }

            if (x - 1 >= 0 && a[x - 1] == false) {                
                q.push(x - 1);
                a[x - 1] = true;
                cnt++;
            }
        }    
        level++;

        seg = cnt;
        cnt = 0;
    }
}

int main() {

    cin >> N >> K;

    for (int i = 0; i < MAX; i++) {
        a[i] = false;
    }

    bfs(N);

    cout << level;

    return 0;
}


/*
    Algorithm : BFS

    Time complexity : O(n)

*/