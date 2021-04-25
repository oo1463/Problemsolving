// https://www.acmicpc.net/problem/2800

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

vector<pair<int,int>> v;
int sz;
int vsz;
bool visit[10];
string ts;
string s;
vector<string> ans_vector;

bool check_all_false(){
    for(int i=0; i<vsz; i++){
        if(visit[i] == true) return false;
    }
    return true;
}

void recur(int cnt){
    if(cnt >= vsz){
        if(check_all_false()) return;
        string ss;
        ts = s;           
        for(int i=0; i<vsz; i++){
            if(visit[i] == true){
                ts[v[i].first] = 'x';
                ts[v[i].second] = 'x';
            }
        }
        for(int i=0; i<sz; i++){
            if(ts[i] != 'x') ss += ts[i];
        }
        ans_vector.push_back(ss);

        return;
    }

    visit[cnt]=true;
    recur(cnt+1);
    visit[cnt]=false;
    recur(cnt+1);
}

int main() {
    FAIO;

    cin >> s;
    stack<int> st;
    sz = s.size();    
    for(int i=0; i<sz; i++){
        if(s[i] == '(') st.push(i);
        else if(s[i] == ')'){
            v.push_back({st.top(), i});
            st.pop();
        }
    }

    vsz = v.size();

    recur(0);
    sort(ans_vector.begin(),ans_vector.end());
    unique(ans_vector.begin(), ans_vector.end());
    for(int i=0; i<ans_vector.size(); i++){        
        if(ans_vector[i].empty()) break;
        cout << ans_vector[i] << el;
    }

   
    return 0;
}


/*
    Algorithm : string, recur

    Time complexity : O(2^N * length)
    
*/
