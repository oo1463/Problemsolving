#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_prime(int N) {
	if (N == 1) return false;
	if (N == 2) return true;

	for (int i = 2; i*i <= N; i++) {
		if (N % i == 0) return false;		
	}
	return true;
}


int main() {

	int M, N;

	cin >> M >> N;

	for (int i = M; i <= N; i++)
		if (is_prime(i)) cout << i << '\n';

	return 0;
}