#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int countn;

void dfs(int arri, int sum, int n) {
	int i;
	if (sum == n) {
		countn++;
		return;
	}
	else if (sum > n) return;


	for (i = 1; i <= 3; i++) {
		arr[arri] = i;
		dfs(arri+1, sum + i,n);
	}
}

int main() {

	int T, n;

	cin >> T;
	for (int i = 0; i < T; i++) {
		countn = 0;
		cin >> n;
		dfs(0, 0, n);
		cout << countn << '\n';		
	}	
	

	return 0;
}