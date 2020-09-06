#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int N, M;
vector<pair<string, int> > v;

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

        int g;
        cin >> g;
        int answer = 100000000;

        int left = 0, right = v.size() - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;

            if (v[mid].second >= g) {
                right = mid - 1;
                if (answer >= mid) answer = mid;
            }
            else if (v[mid].second < g) {
                left = mid + 1;
            }
        }

        cout << v[answer].first << el;
    }

    return 0;
}
