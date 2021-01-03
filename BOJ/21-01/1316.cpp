// https://www.acmicpc.net/problem/1316

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

    int N;
    string word[101];
    bool al[26];

    cin >> N;
    for(int i=0; i<N; i++) cin >> word[i];
    int cnt = N;

    for(int i=0; i<N; i++){
        memset(al, false, sizeof(al));
        al[word[i][0]-'a'] = true;
        for(int j=1; j<word[i].size(); j++){
            if(word[i][j] != word[i][j-1]){
                if(al[word[i][j]-'a']) {
                    cnt--;
                    break;
                }
                al[word[i][j]-'a'] = true;
            }
        }
    }
   
    cout << cnt;

    return 0;
}



/*
    Algorithm : string

    Time complexity : O(N)
    
*/
