// https://www.acmicpc.net/problem/

//시간제한  메모리
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

char ma[11][11];
char smap[11][11][11];
int N, M;

bool left(pair<int, int>* color, char map[11][11]) {
    while (color->second > 1) {
        if (map[color->first][color->second - 1] == '.') {
            map[color->first][color->second - 1] = map[color->first][color->second];
            map[color->first][color->second] = '.';
            color->second++;
        }
        else if (map[color->first][color->second - 1] == 'O') {
            map[color->first][color->second] = '.';
            return false;
        }
        else break;
    }
    return true;
}

bool right(pair<int, int>* color, char map[11][11]) {
    while (color->second < M) {
        if (map[color->first][color->second + 1] == '.') {
            map[color->first][color->second + 1] = map[color->first][color->second];
            map[color->first][color->second] = '.';
            color->second++;
        }
        else if (map[color->first][color->second + 1] == 'O') {
            map[color->first][color->second] = '.';
            return false;
        }
        else break;
    }
    return true;

}

bool down(pair<int, int>* color, char map[11][11]) {
    while (color->second < M) {
        if (map[color->first + 1][color->second] == '.') {
            map[color->first + 1][color->second] = map[color->first][color->second];
            map[color->first][color->second] = '.';
            color->first++;
        }
        else if (map[color->first + 1][color->second] == 'O') {
            map[color->first][color->second] = '.';
            return false;
        }
        else break;
    }
    return true;
}

bool up(pair<int, int>* color, char map[11][11]) {
    while (color->second < M) {
        if (map[color->first - 1][color->second] == '.') {
            map[color->first - 1][color->second] = map[color->first][color->second];
            map[color->first][color->second] = '.';
            color->second++;
        }
        else if (map[color->first - 1][color->second] == 'O') {
            map[color->first][color->second] = '.';
            return false;
        }
        else break;
    }
    return true;
}

int move(int where, char tmap[11][11]) {

    pair<int, int> red, blue;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tmap[i][j] == 'R') red = make_pair(i, j);
            else if (tmap[i][j] == 'B') blue = make_pair(i, j);
        }
    }

    switch (where) {
    case 1:
        left(&red, tmap);
        left(&blue, tmap);
        r = left(&red, tmap);
        b = left(&blue, tmap);
        break;
    case 2:
        right(&red, tmap);
        right(&blue, tmap);
        r = right(&red, tmap);
        b = right(&blue, tmap);
        break;
    case 3:
        down(&red, tmap);
        down(&blue, tmap);
        r = down(&red, tmap);
        b = down(&blue, tmap);
        break;
    case 4:
        up(&red, tmap);
        up(&blue, tmap);
        r = up(&red, tmap);
        b = up(&blue, tmap);
        break;
    }
    if (r == false && b == true) return 1;
    if (r == true && b == false) return -1;
    if (r == true && b == true) return 0;
    if (r == false && b == false) return -1;
}

void dfs(int arri) {
    if (arri == 11) {
        cout << "-1";
        return;
    }

    for (int i = 1; i <= 4; i++) {
        if (move(i) == 1) {

        }
    }
}

int main() {
    FAIO;

    string s[11];
    pair<int, int> startred;
    pair<int, int> startblue;

    for (int i = 0; i <= N; i++) {
        cin >> s[i];
        for (int j = 0; j < M; j++) {
            map[i][j] = s[i][j];
            if (map[i][j] == 'R') startred = make_pair(i, j);
            if (map[i][j] == 'B') startblue = make_pair(i, j);
        }
    }



    return 0;
}


/*
    Algorithm :

    Time complexity : O(N^2)

*/