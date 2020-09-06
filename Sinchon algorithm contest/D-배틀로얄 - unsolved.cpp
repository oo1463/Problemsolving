#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int X, Y, M;
int P[100002];
int H[100002];

int main() {
    FAIO;

    cin >> X >> Y >> M;
    int sump = 0, sumh = 0;
    for (int i = 1; i <= X; i++) {
        cin >> P[i];
        sump += P[i];
    }
    for (int i = 1; i <= Y; i++) {
        cin >> H[i];
        sumh += H[i];
    }
    if (M + sumh <= sump) {
        cout << '0';
        return 0;
    }

    int i = 1, j = 1;
    int nowh = M;
    vector<int> v;
    while (i <= X) {
        if (nowh - P[i] > 0) {
            nowh -= P[i];          
            v.push_back(-i);
            //cout << '-' << i << el;
            i++;
        }
        else {
            nowh += H[j];
            v.push_back(j);
            //cout << j << el;
            j++;
        }
    }

    if (i <= X) {
        cout << '0';
        return 0;
    }

    for (int i = 0; i < v.size(); i++) cout << v[i] << el;

    while (j <= Y) {
        cout << j << el;
        j++;
    }

    return 0;
}
