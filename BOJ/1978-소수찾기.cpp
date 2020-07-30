#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int N;
	int arr[101];
	int count = 0;

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	for (int i = 0; i < N; i++) {
		if (arr[i] == 2) count++;
		for (int j = 2; j < arr[i]; j++) {
			if (arr[i] % j == 0) break;
			if (j == arr[i] - 1) count++;
		}
	}

	cout << count;

	return 0;
}