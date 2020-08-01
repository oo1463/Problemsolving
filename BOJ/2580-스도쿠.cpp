#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int s[9][9];

bool check(int x, int y) { 

	for (int i = 0; i < 9 ; i++) {				
		if (s[x][y] == s[i][y] && x != i) return false;
	}

	for (int i = 0; i < 9; i++) {		
		if (s[x][y] == s[x][i] && y != i) return false;
	}

	for (int i = x - (x % 3); i < x-(x % 3) + 3; i++) {		
		for (int j = y - (y % 3); j < y-(y % 3) + 3; j++) {
			if (i == x && j == y);
			else if (s[x][y] == s[i][j]) {								
				return false;
			}
		}
	}

	return true;
}

bool is_finished() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (s[i][j] == 0) return false;
		}
	}
	return true;
}

void dfs(int x, int y, int value) {

	
	
	if (s[x][y] != value);
	else 
		if (!check(x, y)) return;

	//for (int i = 0; i < 9; i++) {
	//	for (int j = 0; j < 9; j++) {
	//		cout << s[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	//cout << '\n';

	
	
	for (int i = x; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (s[i][j] == 0) {
				for (int k = 1; k <= 9; k++) {
					s[i][j] = k;
					dfs(i, j, k);
					s[i][j] = 0;
				}
				return;
			}
		}		
	}

	if (is_finished()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << s[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}

}

int main() {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> s[i][j];
		}
	}

	dfs(0, 0, -1);

	return 0;
}