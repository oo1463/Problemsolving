// https://www.acmicpc.net/problem/14890

//시간제한  메모리
//2 초	512 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, len;
int map[101][101];
int map2[101][101];

bool exist[101][101];

bool possi[101];
bool possj[101];



int main() {
    FAIO;

    cin >> N >> len;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            map2[j][i] = map[i][j];
        }
    }

    memset(possi, true, sizeof(possi));
    memset(possj, true, sizeof(possj));


    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (map[i][j] != map[i][j + 1]) {
                if (abs(map[i][j] - map[i][j + 1]) > 1) {
                    possi[i] = false;
                    break;
                }
                else if (map[i][j] > map[i][j + 1] ) {
                    for (int k = j + 1; k < j + len && k < N; k++) {
                        if ((map[i][k] != map[i][k + 1] || exist[i][k] || exist[i][k + 1]) && len > 1) {
                            possi[i] = false;
                            break;
                        }
                        else {
                            if ((len == 1) && exist[i][k]) {
                                possi[i] = false;
                                break;
                            }
                            exist[i][k] = true;
                        }
                    }
                    exist[i][j + len - 1] = true;

                }
                else {
                    for (int k = j; k > j - len + 1 && k > 0; k--) {
                        if ((map[i][k] != map[i][k - 1] || exist[i][k] || exist[i][k - 1]) && len > 1) {
                            possi[i] = false;
                            break;
                        }
                        else {
                            if ((len == 1) && exist[i][k]) {
                                possi[i] = false;
                                break;
                            }
                            exist[i][k] = true;
                        }
                    }
                    exist[i][j - len] = true;

                }

                if (!possi[i]) break;

            }
        }
    }

    memset(exist, false, sizeof(exist));


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (map2[i][j] != map2[i][j + 1]) {
                if (abs(map2[i][j] - map2[i][j + 1]) > 1) {
                    possj[i] = false;
                    break;
                }
                else if (map2[i][j] > map2[i][j + 1]) {
                    for (int k = j + 1; k < j + len && k < Nd; k++) {
                        if ((map2[i][k] != map2[i][k + 1] || exist[i][k] || exist[i][k+1]) && len > 1) {
                            possj[i] = false;
                            break;
                        }
                        else {
                            if ((len == 1) && exist[i][k]) {
                                possj[i] = false;
                                break;
                            }
                            exist[i][k] = true;
                        }
                    }
                    exist[i][j + len - 1] = true;

                }

                else {
                    for (int k = j; k > j - len + 1 && k>0 ; k--) {
                        //cout << i << ' ' << j << ' ' << k << ' ' << ' ' << map2[i][k] << ' ' << map2[i][k - 1] << "   " << exist[i][k] << ' ' << exist[i][k - 1] <<  el;
                        if (len > 1 && (map2[i][k] != map2[i][k - 1] || exist[i][k] || exist[i][k - 1])) {
                            possj[i] = false;
                            break;
                        }
                        else {
                            if ((len == 1) && exist[i][k]) {
                                possj[i] = false;
                                break;
                            }
                            exist[i][k] = true;                            
                        }
                    }
                    exist[i][j-len] = true;
                }

                if (!possj[i]) break;
            }
        }
    }
    cout << el;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (possi[i]) cnt++;
        cout << possi[i] << ' ';
    }
    cout << el;

    for (int i = 0; i < N; i++) {
        if (possj[i]) cnt++;
        cout << possj[i] << ' ';        
    }
    cout << el;

    cout << cnt;

    return 0;
}


/*
    Algorithm :

    Time complexity : O(N^2)

*/