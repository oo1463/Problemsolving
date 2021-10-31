// https://www.acmicpc.net/problem/1531

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, M;
int map[101][101];

int main()
{
    FAIO;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i <= x2; i++)
        {
            for (int j = y1; j <= y2; j++)
            {
                map[i][j]++;
            }
        }
    }

    int cnt = 0;

    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            if (map[i][j] > M)
                cnt++;
        }
    }

    cout << cnt;

    return 0;
}

/*
    Algorithm : simulation

    Time complexity : O(N^2)
    
*/
