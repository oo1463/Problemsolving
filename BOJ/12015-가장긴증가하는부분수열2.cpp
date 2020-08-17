// https://www.acmicpc.net/problem/12015

//시간제한  메모리
//1 초	512 MB

#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

int main() {

    int N, temp, cnt = 0;
    vector <int> v;

    v.push_back(INT_MIN);

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        if (temp > v.back()) { v.push_back(temp); cnt++; }
        else {
            vector<int>::iterator low = lower_bound(v.begin(), v.end(), temp);
            *low = temp;
        }
    }

    printf("%d\n", cnt);

    return 0;
}


/*
    Algorithm : 

    Time complexity : O(NlogN)

*/