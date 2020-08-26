// https://www.acmicpc.net/problem/1695

//시간제한  메모리
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;
typedef struct a {
    int left;
    int right;
    int level;
}aa;

int N;
int a[5001];
queue<aa > q;
bool visited[5001][5001];

int main() {
    FAIO;

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i];

    aa first = { 1,N,0 };
    q.push(first);
    
    while (!q.empty()) {
        aa tmp = q.front();        
        q.pop();        

        while (1) {
            if (a[tmp.left] == a[tmp.right]) {
                tmp.left += 1;
                tmp.right -= 1;
            }
            else break;
        }

        if (tmp.left >= tmp.right) {
            cout << tmp.level;
            return 0;
        }

        if (tmp.left < tmp.right) {
            aa tmp1 = tmp;
            tmp1.left++;
            aa tmp2 = tmp;
            tmp2.right--;

            tmp1.level = tmp.level + 1;
            tmp2.level = tmp.level + 1;
            
            if (!visited[tmp1.left][tmp1.right]) {
                q.push(tmp1);
                visited[tmp1.left][tmp1.right] = true;
            }
            
            if (!visited[tmp2.left][tmp2.right]) {
                q.push(tmp2);
                visited[tmp2.left][tmp2.right] = true;
            }
        }
    }

    return 0;
}


/*
    Algorithm : BFS

    Time complexity : O(N)

*/