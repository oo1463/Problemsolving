#include <iostream>
#include <algorithm>
using namespace std;

int part[20];
int arr[20];
int N, S;
int counta;

void dfs(int si, int arri, int sum) {
	int i;
	if (sum == S && arri > 0) {
		counta++;		
	}

	for (i = si; i < N; i++) {
		part[arri] = arr[i];
		dfs(i + 1, arri + 1, sum + part[arri]);
	}
}

int main() {

	cin >> N >> S;
	counta = 0;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}		
	dfs(0, 0, 0);

	cout << counta;

	return 0;
}