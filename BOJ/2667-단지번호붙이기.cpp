// https://www.acmicpc.net/problem/2667

//시간제한  메모리
//1 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


typedef struct hous {
    bool here;
    bool visited;
}hous;

typedef struct xy {
    int x;
    int y;
}xy;

vector<int> house;
queue<xy> q;
hous h[26][26];
int N;

void bfs(int x, int y) {

    h[x][y].visited = true;
    int c = 0;
    xy tmpxy;
    tmpxy.x = x;
    tmpxy.y = y;
    xy tmp2;
    int countb = 0;
    q.push(tmpxy);

    while (!q.empty()) {

        tmpxy = q.front();
        q.pop();
        countb++;
        c++;
        if(tmpxy.x > 1)
            if (h[tmpxy.x - 1][tmpxy.y].here == 1 && h[tmpxy.x - 1][tmpxy.y].visited == false) {
                tmp2.x = tmpxy.x - 1;
                tmp2.y = tmpxy.y;
                q.push(tmp2);
                h[tmpxy.x - 1][tmpxy.y].visited = true;
            }

        if (tmpxy.y > 1)
            if (h[tmpxy.x][tmpxy.y - 1].here == 1 && h[tmpxy.x][tmpxy.y - 1].visited == false) {
                tmp2.x = tmpxy.x ;
                tmp2.y = tmpxy.y - 1;
                q.push(tmp2);
                h[tmpxy.x][tmpxy.y - 1].visited = true;
            }

        if (tmpxy.x < N)
            if (h[tmpxy.x + 1][tmpxy.y].here == 1 && h[tmpxy.x + 1][tmpxy.y].visited == false) {
                tmp2.x = tmpxy.x + 1;
                tmp2.y = tmpxy.y;
                q.push(tmp2);
                h[tmpxy.x + 1][tmpxy.y].visited = true;
            }

        if(tmpxy.y < N)
            if (h[tmpxy.x][tmpxy.y + 1].here == 1 && h[tmpxy.x][tmpxy.y + 1].visited == false) {
                tmp2.x = tmpxy.x;
                tmp2.y = tmpxy.y + 1;
                q.push(tmp2);
                h[tmpxy.x][tmpxy.y + 1].visited = true;
            }
    }
    house.push_back(countb);
}


int main() {
    int counta = 0;
    cin >> N;
    string arr[26];

    for (int i = 1; i <= N; i++) cin >> arr[i];

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == '1') {
                h[i][j+1].here = true;
                h[i][j+1].visited = false;
            }
            else {
                h[i][j+1].here = false;
                h[i][j+1].visited = true;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (h[i][j].here == true && h[i][j].visited == false) {
                counta++;
                bfs(i, j);
            }

        }
    }

    cout << counta << '\n';

    sort(house.begin(), house.end());

    for (unsigned int i = 0; i < house.size(); i++) {
        cout << house[i] << '\n';
    }

    return 0;
}


/*
    Algorithm : BFS

    Time complexity : O(N^4)

*/  