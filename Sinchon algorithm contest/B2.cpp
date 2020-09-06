#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, M;
vector<pair<string, int> > v;

bool cmp(pair<string, int> a, pair<string, int> b) { return a.second <= b.second; }

int main() {
    FAIO;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string ts;
        int ti;
        cin >> ts >> ti;
        v.push_back(make_pair(ts, ti));
    }

    while (M--) {

        pair<string, int> g;

        cin >> g.second;
        auto a = upper_bound(v.begin(), v.end(), g , cmp);

        cout << a->first << el;
    }

    return 0;
}
