#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int i, j;
int count2 = 0;
void dfs(int x, int y, int count1, int m[16][16]) {
	if (m[x][y] == -1) return;

	int map[16][16];
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++) map[i][j] = m[i][j];

	if (x > 0 && y > 0) {
		map[x][y] = 1;
		count1++;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N ; j++) {
				if (x == i && y == j);

				else if (x == i || y == j) {
					map[i][j] = -1;
				}
				else
					for (int k = 1; k <= N; k++) {
						if ((i == x + k && j == y + k) || (i == x + k && j == y - k) || (i == x - k && j == y - k) || (i == x - k && j == y + k)) {
							map[i][j] = -1;
						}
					}
			}
		}

	}
	
	
		

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 0) dfs(i, j, count1, map);
		}
	}
		

	
	
	if (count1 == N) {	
		count2++;
		return;
	}
}

int main() {

	cin >> N;
	int map2[16][16];

	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++)
			map2[i][j] = 0;

	dfs(0, 0, 0, map2);
	cout << count2 << endl;
}