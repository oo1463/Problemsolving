#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m; string input1, input2;
vector <pair<string, string> > list;

int search(int l, int r, string a) {
    int mid = (l + r) / 2; // 기준점을 중앙으로 잡는다.
    if (list[mid].first == a) return mid; // 기준점과 찾는 주소가 같으면 기준점을 반환해준다.

    return list[mid].first >= a ? search(l, mid, a) : search(mid + 1, r, a);
    // 배열의 기준점에 해당하는 주소보다 작으면 앞쪽, 크면 뒤쪽을 찾는다.
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> input1 >> input2;
        list.push_back({ input1,input2 }); // 주소와 비밀번호를 pair로 묶어 벡터에 넣어준다.
    }
    sort(list.begin(), list.end()); // 배열을 오름차순으로 정렬해준다.

    for (int i = 0; i < m; i++) {
        cin >> input1;
        int x = search(0, n - 1, input1);
        cout << list[x].second << '\n';
    }
}