#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int s[13];
int arr[6];
int k;

void dfs(int si, int arri) {
	int i;
	if (arri == 6) {
		for (i = 0; i < 6; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
		
	
	for (i = si; i < k; i++) {
		arr[arri] = s[i];
		dfs(i + 1, arri + 1);
	}
}

int main() {


	while (1) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) cin >> s[i];
		dfs(0, 0);
		cout << '\n';
	}
	

	return 0;
}