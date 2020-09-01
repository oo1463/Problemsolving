#include <iostream>
#include <vector>

using namespace std;

typedef struct a {
	int index;
	int matter;
}arr;

void solve(vector<arr> vec, int M) {
	int count = 0;

	for (auto a = vec.begin(); a != vec.end();) {
		if (vec.front().matter < a->matter) {
			vec.push_back(vec.front());
			vec.erase(vec.begin());
			a = vec.begin();
		}
		else if (next(a, 1) == vec.end()) {
			count++;
			if (vec.front().index == M) {
				cout << count << endl;
				break;
			}
			else {
				vec.erase(vec.begin());
				a = vec.begin();
			}
		}
		else a++;
	}

}

int main() {
	
	int testcase, N, M;
	int i,j;
	vector<arr> vec;
	arr tmp;

	cin >> testcase;
	for (i = 0; i < testcase; i++) {		
		vec.clear();

		cin >> N >> M;
		for (j = 0; j < N; j++) {
			cin >> tmp.matter;
			tmp.index = j;
			vec.push_back(tmp);						
		}
		solve(vec, M);		
	}

	return 0;
}