// https://www.acmicpc.net/problem/9576

//시간제한  메모리
//2 초	256 MB //

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

typedef struct a {
    int a;
    int b;
}st;

int N, M;
st stde[1001];

bool cmp(st x, st y) {    
    if (x.b == y.b) return x.a < y.a;
    else return x.b < y.b;
}

int main() {
    FAIO;
    int T;
    cin >> T;

    while (T--) {
        bool book[1001] = { false };

        int cnt = 0;
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            cin >> stde[i].a >> stde[i].b;
        }

        sort(stde, stde + M, cmp);

        for (int i = 0; i < M; i++) {
            cout << stde[i].a << ' ' << stde[i].b << el;
        }

        for (int i = 0; i < M; i++) {
            for (int j = stde[i].a; j <= stde[i].b; j++) {
                if (!book[j]) {
                    book[j] = true;
                    cnt++;
                    break;
                }
            }
        }

        cout << cnt << el;
    }

    return 0;
}
    

/*
    Algorithm : Greedy

    Time complexity : O(M^2)

*/