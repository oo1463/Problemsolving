#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
string str;
int flag;

bool check(string stri) {
	int len = stri.length();

	//for (int s = 2; s <= len ; s+=2) {
	//	for (int i = 0; i <= len - s; i++) {			
	//		if (stri.substr(i, s / 2) == (stri.substr(i + s / 2 , s / 2))) return false;									
	//	}				
	//}	

	for (int s = 1; s <= len/2; s++) {
		if (stri.substr(len - 2 * s, s) == stri.substr(len - s, s)) return false;
	}

	return true;
}


void dfs(int arri) {	
	if (!check(str)) return;	
	if (arri == N) {		
		cout << str;
		flag = 1;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if (flag == 1) return;
		str += to_string(i);
		dfs(arri + 1);
		str.pop_back();
	}
}


int main() {

	cin >> N;		
	dfs(0);
	return 0;
}