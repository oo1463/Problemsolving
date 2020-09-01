#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	
	int N, yn;
	int y[51];

	cin >> yn;
	for (int i = 0; i < yn; i++) {
		cin >> y[i];
	}

	sort(y, y + yn);

	cout << y[0] * y[yn - 1] << '\n';

	return 0;
}