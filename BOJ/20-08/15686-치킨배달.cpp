#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct xt {
	int x;
	int y;
}loc;

vector<loc> house;
vector<loc> chicken;
loc left_c[14];
int count1;
int N, M;
int tmp = 2100000000;

int get_min(int a, int b) { return a < b ? a : b; }

int abs2(int a) {
	if (a < 0) return -a;
	else return a;
}

void dfs(int s, int arri) {	
	if (arri == M) {
		int distance;
		int min;

		count1 = 0;
		for (int i = 0; i < house.size(); i++) {
			min = 2100000000;
			for (int j = 0; j < M; j++) {
				distance = abs2(house[i].x - left_c[j].x) + abs2(house[i].y - left_c[j].y);
				min = get_min(min, distance);
			}			
			count1 += min;
		}

		tmp = get_min(count1, tmp);

		return;
	}

	for (int i = s; i < chicken.size(); i++) {		
		left_c[arri] = chicken[i];
		dfs(s + 1, arri + 1);
	}
}

int main() {

	int matrix[51][51];
	loc tmploc;
	count1 = 0;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> matrix[i][j];
			tmploc.x = i;
			tmploc.y = j;
			if (matrix[i][j] == 1) house.push_back(tmploc);
			else if (matrix[i][j] == 2) chicken.push_back(tmploc);
		}
	}	
	dfs(0, 0);
	cout << tmp;

	return 0;
}