// https://www.acmicpc.net/problem/9328

#include <iostream>

#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int w,h;
bool visited[102][102];
queue<pair<int,int>> q;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
string map[102];
int cnt = 0;
string keys;

void bfs(int starth, int startw){
    visited[starth][startw] = true;
    q.push({starth, startw});

    while(!q.empty()){
        int nowx = q.front().first;
        int nowy = q.front().second;

        // cout << nowx << ' ' << nowy << el;
        if(map[nowx][nowy] == '$'){
            map[nowx][nowy] = '.';
            cnt++;
        }

        if(map[nowx][nowy] >= 'a' && map[nowx][nowy] <= 'z'){
            keys+=map[nowx][nowy];
            map[nowx][nowy] = '.';
        }
        q.pop();

        for(int i=0; i<4; i++){
            int tx = nowx + dx[i];
            int ty = nowy + dy[i];
            if(tx >= 0 && tx <= h+1 && ty >= 0 && ty <= w+1 && map[tx][ty] != '*' && !(map[tx][ty] >= 'A' && map[tx][ty] <='Z')&& !visited[tx][ty]){
                q.push({tx,ty});
                visited[tx][ty] = true;
            }
        }
    }
}


void print_map(){
    cout << el;

    for(int i=0; i<=h+1; i++){
        for(int j=0; j<=w+1; j++){
            cout << map[i][j];
        }
        cout << el;
    }
    cout << keys << el;
    cout << el;
}


int main() {
    FAIO;

    int T;
    cin >> T;
    while(T--){
        
        for(int i=0; i<101; i++) map[i].clear();

        memset(visited, false, sizeof(visited));
        cnt = 0;
        keys = "";

        cin >> h >> w;
        for(int i=0; i<=w+1; i++) map[0].push_back('.');
        for(int i=0; i<=w+1; i++) map[h+1].push_back('.');
        for(int i=1; i<=h; i++){
            cin >> map[i];
            map[i] = '.' + map[i];
            map[i] +='.';
        }
        cin >> keys;

        while(!keys.empty()){
            for(int i=1; i<=h; i++){
                for(int j=1; j<=w; j++){
                    if(map[i][j] >= 'A' && map[i][j] <= 'Z'){
                        for(int k=0; k<keys.size(); k++){
                            if(toupper(keys[k]) == map[i][j]) map[i][j] = '.';
                        }
                    }
                }
            }
            keys = "";

            // print_map();
            
            bfs(0,0);
            memset(visited, false, sizeof(visited));
            // print_map();
        }

        
        cout << cnt << el;

    }    
   
    return 0;
}


/*
    Algorithm : simulation, BFS

    Time complexity : O(Twh)
    
*/
