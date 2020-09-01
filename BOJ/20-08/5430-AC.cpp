#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <deque>

using namespace std;

deque<int> tokenize_getline(const string& data, const char delimiter = ',') {
	deque<int> result;
	string token;
	stringstream ss(data);

	while (getline(ss, token, delimiter)) {
		result.push_back(stoi(token));
	}
	return result;
}

int main(){

	int T;
	string p;
	int n;
	string strx;
	deque<int> x;
	int i,j,flag,error;
	cin >> T;

	for (i = 0; i < T; i++) {
		cin >> p;
		cin >> n;
		cin >> strx;
		x.clear();
		flag = 1;
		error = 0;

		strx.pop_back();
		strx.erase(strx.begin());
		x = tokenize_getline(strx, ',');

		for (j = 0; j < p.length(); j++)
			if (p[j] == 'R') flag *= -1;
			else if (p[j] == 'D')
				if (!x.empty())
					if (flag == 1) x.pop_front();
					else x.pop_back();
				else {
					error = 1;
					break;
				}
		
		if (error == 1) cout << "error";
		else {
			if (x.empty()) cout << "[]";
			else {
				if (flag == -1) reverse(x.begin(), x.end());
				cout << '[';
				for (auto a = x.begin(); a != x.end(); a++)
					if (next(a, 1) == x.end()) cout << *a << ']';
					else cout << *a << ',';
			}
		}

		if (i < T - 1) cout << '\n';
	}
}