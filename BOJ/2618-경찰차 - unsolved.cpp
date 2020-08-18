// https://www.acmicpc.net/problem/2618

//시간제한  메모리
//1 초	128 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

typedef struct a {
    int x;
    int y;
}pos;

int dist(pos a, pos b) { return (abs(a.x - b.x) + abs(a.y - b.y)); }

int N, W;
int map[1001][1001];
pos acc[1001];
int dp[1001];
int get_min(int a, int b) { return a < b ? a : b; }

int case_solve(pos* a, pos* b) {
    int d = dist(*a, *b);
    b->x = a->x;
    b->y = a->y;
    
    return d;
}

int main() {
    FAIO;

    cin >> N >> W;

    pos car1[1001];
    pos car2[1001];

    for (int i = 0; i < W; i++) cin >> acc[i].x >> acc[i].y;

    car1[0] = { 1,1 };
    car2[0] = { N,N };

    dp[0] = 0;
    pos tc1 = car1[0];
    pos tc2 = car2[0];
    dp[1] = get_min(case_solve(&acc[0], &tc1), case_solve(&acc[0], &tc2));
    car2[1] = tc1;
    car2[1] = tc2;
    
    for (int i = 2; i <= W; i++) {
        pos tmpc1 = car1[i - 2];
        pos tmpc2 = car2[i - 2];

        //cout << acc[i - 1].x << ' ' << acc[i - 1].y << ' ' << tmpc1.x << ' ' << tmpc1.y << ' ' << dist(acc[i-1],tmpc1) << el;

        int tmp1 = case_solve(&acc[i-2], &tmpc1) + case_solve(&acc[i-1],&tmpc1);
        //cout << acc[i - 1].x << ' ' << acc[i - 1].y << ' ' << tmpc1.x << ' ' << tmpc1.y <<' '<< tmp1<< el;

        tmpc1 = car1[i - 2];
        tmpc2 = car2[i - 2];
        int tmp2 = case_solve(&acc[i-2], &tmpc1) + case_solve(&acc[i-1], &tmpc2);
        tmpc1 = car1[i - 2];
        tmpc2 = car2[i - 2];
        int tmp3 = case_solve(&acc[i-2], &tmpc2) + case_solve(&acc[i-1], &tmpc1);
        tmpc1 = car1[i - 2];
        tmpc2 = car2[i - 2];
        int tmp4 = case_solve(&acc[i-2], &tmpc2) + case_solve(&acc[i-1], &tmpc2);
        tmpc1 = car1[i - 2];
        tmpc2 = car2[i - 2];

        int min = get_min(tmp1,get_min(tmp2, get_min(tmp3, tmp4)));
        if (min == tmp1) {
            case_solve(&acc[i - 2], &tmpc1) + case_solve(&acc[i-1], &tmpc1);
            car1[i - 1] = tmpc1;
            car2[i - 1] = tmpc2;
        }
        else if (min == tmp2) {
            case_solve(&acc[i - 2], &tmpc1) + case_solve(&acc[i-1], &tmpc2);
            car1[i - 1] = tmpc1;
            car2[i - 1] = tmpc2;
        }
        else if (min == tmp3) {
            case_solve(&acc[i - 2], &tmpc2) + case_solve(&acc[i-1], &tmpc1);
            car1[i - 1] = tmpc1;
            car2[i - 1] = tmpc2;
        }
        else if (min == tmp4) {
            case_solve(&acc[i - 2], &tmpc2) + case_solve(&acc[i-1], &tmpc2);
            car1[i - 1] = tmpc1;
            car2[i - 1] = tmpc2;
        }
        cout << car2[i-1].x << ' ' << car2[i-1].y <<' '<< min<< el;


        dp[i] = dp[i - 2] + min;

    }

    cout << dp[1] << ' ' << dp[2] << ' ' << dp[3] << el;
    cout << dp[W];
    return 0;
}


/*
    Algorithm :

    Time complexity : O(N^2)

*/