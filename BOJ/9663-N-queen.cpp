#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N;

int map[15][15];
bool visited[15][15];
bool map_possible[15][15];
bool tmp[15][15][15];

int cnt = 0;

int dx[9] = { 1 , 0 , 0 , -1 , 1 , -1, 1, -1 ,0};
int dy[9] = { 0 , 1 , -1 , 0 , 1 , 1, -1 , -1, 0};

void check(int x, int y, int arri) {
	
	memcpy(tmp[arri], map_possible, sizeof(tmp[arri]));

	for (int i = 0; i < 9; i++) {
		for (int j = 1; j < N; j++) {
			int tmpx = x + dx[i] * j;
			int tmpy = y + dy[i] * j;
			if (tmpx > 0 && tmpy > 0 && tmpx <= N && tmpy <= N) {
				map_possible[tmpx][tmpy] = 0;
			}
		}
	}

}


void dfs(int x, int y, int arri) {
	
	if (arri == N) {
		cnt++;

		//for (int i = 1; i <= N; i++) {
		//	for (int j = 1; j <= N; j++) {
		//		cout << map[i][j] << ' ';
		//	}
		//	cout << endl;
		//}
		//cout << endl;

		return;
	}
	
	x++;
	for (int j = 1; j <= N; j++) {								
		if (map_possible[x][j]) {

			check(x, j, arri);
			//map[x][j] = 1;
			dfs(x, j, arri + 1);
			//map[x][j] = 0;
						 
			memcpy(map_possible, tmp[arri], sizeof(map_possible));
		}
	}
}

int main() {

	memset(map_possible, true, sizeof(map_possible));
	memset(tmp, 1, sizeof(tmp));

	cin >> N;

	for (int i = 1; i <= N; i++) {
		//cout << 1 << ' ' << i << endl;
		check(1, i, 1);
		//map[1][i] = 1;
		dfs(1, i, 1);
		//map[1][i] = 0;
		memset(map_possible, 1, sizeof(map_possible));		

	}
	cout << cnt;

}