#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;

int main() {

	int N;
	int tmp;
	int x;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end());

	int gap = vec.back() - vec.front();
	for (int i = 2; i < N; i++) {
		if (gap % i == 0) {
			gap / i;
			for(int j=0; j<N)
				
		}
		
	}

	cout << vec.back() - vec.front() << endl;

	return 0;
}