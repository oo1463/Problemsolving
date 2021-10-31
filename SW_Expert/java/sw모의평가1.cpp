#ifndef _CRT_SECURE_NO_WARNINGS
	#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int country[10][10];
int fillCnt[10][10];
int army[10][10];
int N;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool is_dead(int cont){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(country[i][j] == cont) return false;
        }
    }
    return true;
}

bool is_finished(){
    
    int con[4];
    for(int i=0; i<4; i++) con[i] = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) {
            con[country[i][j]]++;
        }
    }
    int mx = 0;
    for(int i=1; i<4; i++) if(mx < con[i]) mx = con[i];

    if((N*N - con[0]) == mx) return true;
    else return false;
}

void move_army(vector<pair<pair<int,int>, int> > &move_v){
    for(auto a : move_v){
        // cout << a.first.first << ' ' << a.first.second << ' ' << a.second << " FF" << endl;
        army[a.first.first][a.first.second] += a.second;
    }
}

// 공격
void attack(int cont){
    if(is_dead(cont)) return;

    vector<pair<pair<int,int>, int> > move_v;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(country[i][j] == 0 || country[i][j] == cont) continue;

            int my_army_cnt = 0;
            vector<pair<int,int> > v;

            for(int k=0; k<4; k++) {
                int tx = i + dx[k];
                int ty = j + dy[k];
                if(tx >= 0 && tx < N && ty >= 0 && ty < N){
                    if(country[tx][ty] == cont){
                        my_army_cnt += army[tx][ty];
                        v.push_back(make_pair(tx,ty));
                    }
                }
            }

            if(army[i][j] * 5 < my_army_cnt){
                for(auto a : v){
                    move_v.push_back({{a.first,a.second},-(army[a.first][a.second] / 4)});
                }
                move_v.push_back({{i,j},my_army_cnt/4 + (-army[i][j] * 2)});
                // army[i][j] = my_army_cnt/4 - army[i][j];
                country[i][j] = cont;
            }

        }
    }

    move_army(move_v);

    
}

bool is_other_country_exist(int x, int y, int cont){
    for(int i=0; i<4; i++){
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(tx >= 0 && tx < N && ty >= 0 && ty < N && country[tx][ty] != 0){
            if(country[tx][ty] != cont) return true;
        }
    }
    return false;
}

// 지원
void help(int cont){
    if(is_dead(cont)) return;

    vector<pair<pair<int,int>, int> > move_v;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(country[i][j] != cont) continue;

            if(!is_other_country_exist(i,j, cont)){
                for(int k=0; k<4; k++){
                    int tx = i + dx[k];
                    int ty = j + dy[k];
                    if(tx >= 0 && tx < N && ty >= 0 && ty < N && country[tx][ty] != 0){
                        // cout << i << ' ' << j << ' ' << tx << ' ' << ty << ' ' << army[i][j]/5 << endl;
                        move_v.push_back({{tx,ty}, army[i][j]/5});
                        move_v.push_back({{i,j}, -army[i][j]/5});
                    }
                }
            }
            else{
                for(int k=0; k<4; k++){
                    int tx = i + dx[k];
                    int ty = j + dy[k];
                    if(tx >= 0 && tx < N && ty >= 0 && ty < N && country[tx][ty] == cont){
                        if(army[tx][ty] * 5 < army[i][j]){
                            move_v.push_back({{tx,ty}, army[i][j]/5});
                            move_v.push_back({{i,j}, -army[i][j]/5});
                        }
                    }
                }
            }

        }
    }
    move_army(move_v);
}

// 보충
void fill_area(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            army[i][j] += fillCnt[i][j];
        }
    }
}

int cnt_every_army(){
    int sum = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            sum += army[i][j];
        }
    }
    return sum;
}

void print(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) cout << army[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
}

bool is_destroy(int cont){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) if(country[i][j] == cont) return false;
    }
    return true;
}

int main(void)
{
	int test_case;
	int T;

	setbuf(stdout, NULL);

	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		int ans;
		cin >> N;
		
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++) cin >> country[i][j];
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++) cin >> army[i][j];
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++) cin >> fillCnt[i][j];
        }

        int turn = 1;        

        while(1){

            if(is_finished()){
                ans = cnt_every_army();
                break;
            }

            if(is_destroy(turn)){
                turn = turn % 3 + 1;
                continue;
            }
            
            attack(turn);
            print();
            help(turn);
            print();
            fill_area();
            print();
            

            turn = turn % 3 + 1;
        }
		
		cout << "#" << t << ' ' << ans;
	}

	return 0; 
}