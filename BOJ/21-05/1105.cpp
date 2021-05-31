// https://www.acmicpc.net/problem/1105

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;


int main() {
    FAIO;
    int l,r;
    cin >> l >> r;

    string ls = to_string(l);
    string rs = to_string(r);

    if(ls.size() != rs.size()) {
        cout << 0;
        return 0;
    }

    int cnt = 0;

    for(int i=0; i<ls.size(); i++){
        if(ls[i] == '8' && rs[i] == '8'){
            cnt++;
        }
        else if(ls[i] == rs[i]) continue;
        else break;
    }
    
    cout << cnt;
    return 0;
}
