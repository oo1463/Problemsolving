#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int abil[21][21];
int start[21];
vector<int> link;
int count1, count2, count3, count4;
int a[11];
int mina;
int tmp;

int get_min(int a, int b) { return a < b ? a : b; }

void dfs2(int si, int arri, int people[11]) {

	if (arri == 2) {
		count1 += abil[a[0] - 1][a[1] - 1] + abil[a[1] - 1][a[0] - 1];
		//cout << a[0] << ' ' << a[1]<< "   " << count1 << '\n';

		return;
	}

	for (int i = si; i < N / 2; i++) {
		a[arri] = people[i];
		dfs2(i + 1, arri + 1, people);
	}
}

void dfs2(int si, int arri, vector<int> people) {

	if (arri == 2) {
		count2 += abil[a[0] - 1][a[1] - 1] + abil[a[1] - 1][a[0] - 1];

		//cout << a[0] << ' ' << a[1] <<"   "<< count2 <<'\n';

		return;
	}

	for (int i = si; i < N / 2; i++) {
		a[arri] = people[i];
		dfs2(i + 1, arri + 1, people);
	}
}

void dfs(int si, int arri) {
	if (arri == N/2) {
		link.clear();
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < N/2; j++) {
				if (start[j] == i) break;
				else if ((j + 1 == N / 2)) link.push_back(i);					
			}
		}
		
		/*for (int i = 0; i < N / 2; i++) cout << start[i] << ' ';
		cout << endl;
		for (int i = 0; i < N / 2; i++) cout << link[i] << ' ';
		cout << endl;*/
		count1 = 0;
		count2 = 0;

		dfs2(0, 0, start);
		dfs2(0, 0, link);

		tmp = abs(count1 - count2);
		//cout << tmp << ' ' << endl;
		mina = get_min(mina, tmp);		
		return;
	}


	for (int i = si; i < N; i++) {
		start[arri] = i+1;
		dfs(i + 1, arri + 1);
	}
}




int main() {

	int i, j;

	cin >> N;
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) cin >> abil[i][j];
	}

	tmp = 0;
	mina = 10000000;
	dfs(0, 0);
	cout << mina;

	return 0;
}