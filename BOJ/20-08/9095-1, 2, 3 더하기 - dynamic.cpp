#include <iostream>
#include <algorithm>
using namespace std;

int s[100001];

int solve1(int n) {  // ÇÔ¼öÀÇ Àç±Í
	if (n == 1) return 1;
	else if (n == 2) return 2;
	else if (n == 3) return 4;
	else if (n < 1) return 0;
	return solve1(n - 3) + solve1(n - 2) + solve1(n - 1);
}

int solve2(int n) { // dynamic programming
	for (int i = 4; i <= n; i++) {		
		s[i] = s[i - 3] + s[i - 2] + s[i - 1];
	}
	return s[n];
}

int main() {

	int T, n;

	cin >> T;
	
	s[1] = 1;
	s[2] = 2;
	s[3] = 4;

	for (int i = 0; i < T; i++) {
		cin >> n;
		//cout << solve1(n) << '\n';
		cout << solve2(n) << '\n';		
	}


	return 0;
}