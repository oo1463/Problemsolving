#include <iostream>
#include <algorithm>
#include <queue>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

priority_queue<int> pq;
int N;
int centi;
int T;

int main() {
    FAIO;

    cin >> N >> centi >> T;

    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        pq.push(t);
    }

    if (pq.top() < centi) {
        cout << "YES" << el << '0';
        return 0;
    }

    for(int i=1; i<=T; i++) {
        int to = pq.top();
        if (pq.top() == 1) {
            if (centi > 1) {
                cout << "YES" << el << i;
                return 0;
            }
            else cout << "NO" << el << pq.top();
            return 0;
        }
        pq.pop(); // logN
        if(to > 1) to /= 2;
        pq.push(to); // logN
        if (pq.top() < centi) {
            cout << "YES" << el << i;
            return 0;
        }
    }

    if (pq.top() >= centi) cout << "NO" << el << pq.top();


    return 0;
}
