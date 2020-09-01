#include <iostream>
#include <cstring>
#include <math.h>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int K;
int t[5][9];
string ns[5];
bool visited[5];

void rota(int what, int how) {
    int tmp[9];

    if (how == 1) for (int i = 2; i <= 8; i++) tmp[i] = t[what][(i + 6) % 8 + 1];    
    else if (how == -1) for (int i = 1; i <= 8; i++) tmp[i] = t[what][i % 8 + 1];

    memcpy(t[what], tmp, sizeof(t[what]));
}

void recur(int what, int how) {
    visited[what] = true;

    if (what > 1 && !visited[what - 1] && t[what - 1][3] != t[what][7]) recur(what - 1, -how);
    if (what < 4 && !visited[what + 1] && t[what + 1][7] != t[what][3]) recur(what + 1, -how);
    rota(what, how);
    return;
}

int main() {
    FAIO;

    for (int i = 1; i <= 4; i++) {
        cin >> ns[i];
        for (int j = 1; j <= 8; j++) t[i][j] = ns[i][j - 1] - '0';
    }

    cin >> K;
    while (K--) {
        int w, h;
        cin >> w >> h;
        recur(w, h);
        memset(visited, false, sizeof(visited));
    }

    int sum = 0;

    for (int i = 1; i < 5; i++) if (t[i][1] == 1) sum += pow(2, i - 1);

    cout << sum;

    return 0;
}
