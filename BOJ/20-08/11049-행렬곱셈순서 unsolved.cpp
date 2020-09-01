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

vector<pair<int, int> > mat;
vector<pair<int, int> > v;
int N;

int main() {
    FAIO;

    cin >> N;
    int x, y;
    for (int i = 0; i < N; i++){
        cin >> x >> y;
        pair<int, int> tmp = { x,y };
        mat.push_back(tmp);
    }
    //for (int i = 0; i < N; i++) cout << mat[i].first << ' ' << mat[i].second << el;

    int sum = 0;

    while (mat.size() > 1) {
        int len = mat.size();
        int min = mat[0].first * mat[0].second * mat[1].second;
        int tmpi = 0;
        pair<int, int> tmpmat = { mat[0].first, mat[1].second };
        for (int i = 0; i < len - 1; i++) {
            if (mat[i].first * mat[i].second * mat[i + 1].second < min) {
                min = mat[i].first * mat[i].second * mat[i + 1].second;
                tmpmat.first = mat[i].first;
                tmpmat.second = mat[i + 1].second;
                tmpi = i;
            }
        }

        sum += min;

        for (int i = 0; i < len; i++) {
            if (i == tmpi) {
                v.push_back(tmpmat);
                i++;
            }
            else v.push_back(mat[i]);
        }
        //cout << "fuck" << el;

        mat.clear();
        for (int i = 0; i < v.size(); i++) {
            mat.push_back(v[i]);
        }
        //mat.push_back(make_pair(0, 0));

        //copy(v.begin(), v.end(), mat.begin());
        for (int i = 0; i < mat.size(); i++) cout << mat[i].first << ' ' << mat[i].second << el;
        v.clear();

    }

    cout << sum;
    

    return 0;
}


/*
    Algorithm : Greedy

    Time complexity : O(N^2)

*/