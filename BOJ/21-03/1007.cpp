// https://www.acmicpc.net/problem/1007

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

pair<int,int> point[20];

double dist(pair<int,int> a){
    double power = (long long)a.first*a.first + (long long)a.second*a.second;
    // cout << a.first << ' ' << a.second << el;
    return sqrt(power);
}

bool visited[21];
pair<int,int> vect[10];
int N;
int x,y;
double mnDist = 10E20;

int sumX = 0;
int sumY = 0;

void recur(int si, int cnt){
    
    if(cnt == N/2){
        double di = dist({2*x - sumX, 2*y - sumY});
        if(mnDist > di) mnDist = di;
        return;
    }

    for(int i=si; i<N; i++){
        x += point[i].first;
        y += point[i].second;            
        recur(i+1,cnt+1);   
        x -= point[i].first;
        y -= point[i].second;                     
        
    }
    
}


int main() {
    FAIO;

    int T; cin >> T;
    
    while(T--){
        mnDist = 10E20;
        sumX = 0; sumY = 0;
        x=0; y=0;
        memset(visited, false, sizeof(visited));
        cin >> N;
        for(int i=0; i<N; i++){
            cin >> point[i].first >> point[i].second;
            sumX += point[i].first;
            sumY += point[i].second;
        }

        recur(0,0);
        cout.precision(15);
        cout << mnDist << el;
    }   
   
    return 0;
}



/*
    Algorithm : brute force

    Time complexity : O(N^2)
    
*/
