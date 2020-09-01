// https://www.acmicpc.net/problem/12852

//시간제한  메모리
//2 초	512 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N;
bool visited[1000001];
int before[1000001];
queue<int> q;
stack<int> s;

int main() {
    FAIO;

    cin >> N;
    q.push(N);    
    int cnt = 0;

    while (!q.empty()) {
        int num = q.front();
        q.pop();

        if (num == 1) {
            s.push(num);
            while (num != N) {                
                num = before[num];
                s.push(num);
                cnt++;
            }
            cout << cnt << el;
            
            while (!s.empty()) {
                cout << s.top() << ' ';
                s.pop();
            }
            break;
        }

        if (num % 3 == 0 && num / 3 != 0 && !visited[num / 3]) {
            q.push(num / 3);
            visited[num / 3] = true;    
            before[num / 3] = num;
        }
        if (num % 2 == 0 && num / 2 != 0 && !visited[num / 2]) {
            q.push(num / 2);
            visited[num / 2] = true;
            before[num / 2] = num;
        }
        if (num - 1 != 0 && !visited[num - 1]) {
            q.push(num - 1);
            visited[num - 1] = true;
            before[num - 1] = num;
        }
    }

    return 0;
}


/*
    Algorithm : BFS

    Time complexity : O(N)

*/