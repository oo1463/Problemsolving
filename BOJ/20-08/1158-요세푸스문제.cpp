#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {

	int K, N;
	list<int> li;
	list<int>::iterator a;
	list<int>::iterator tmp;
	vector<int> vec;
	vector<int>::iterator b;


	int i;

	cin >> N >> K;

	for (i = 0; i < N; i++)
		li.push_back(i+1);

	for (a = li.begin(), i = 0; ; i++) {		
		if (i % K == K-1) {
			if (a == li.begin()) {
				//cout << *a << ' ';
				vec.push_back(*a);

				li.erase(a);
				a = tmp;
			}
			else {
				//cout << *a << ' ';
				vec.push_back(*a);
				li.erase(a--);
			}
		}
		tmp = a;

		if (li.empty()) break;

		if (next(a, 1) == li.end()) a = li.begin();
		else a++;
	}	

	cout << "<";

	for (b = vec.begin(); b != vec.end(); b++) {
		if (next(b, 1) == vec.end()) cout << *b;
		else cout << *b << ", ";

	}

	cout << ">";

	return 0;
}