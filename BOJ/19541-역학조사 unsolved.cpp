#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Matrix {
public:
	int value[10][10];
	int scope;

	Matrix(int x) {
		for (int i = 0; i < x; i++)
			for (int j = 0; j < x; j++)
				value[i][j] = 0;
		scope = x;
	}

	void setvalue(int i, int j, int v) {
		value[i][j] = v;
	}
};

Matrix multi(Matrix a, Matrix b) {
	Matrix tmpmat(a.scope);
	int tmp = 0;

	for (int i = 0; i < a.scope; i++) {
		for (int j = 0; j < a.scope; j++) {
			for (int k = 0; j < a.scope; k++) {
				tmp += a.value[i][k] * b.value[k][j];
			}
			tmpmat.setvalue(i, j, tmp);
		}
	}
	return tmpmat;
}

int p[10];
int infected[10];
int N,M;
int pmat[10];

vector<Matrix> mat;
vector<int> ar;
int arr[2];
int party;

void dfs(int x,int si, int arri) {
	int i;
	if (arri == 2) {
		mat[x].value[arr[0]-1][arr[1]-1] = 1;
		mat[x].value[arr[1]-1][arr[0]-1] = 1;
		return;
	}


	for (i = si; i < party; i++) {
		arr[arri] = ar[i];
		dfs(x, i + 1, arri + 1);
	}
}



int main() {

	int aa;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		ar.clear();
		cin >> party;
		for (int j = 0; j < party; j++) {
			cin >> aa;				
			ar.push_back(aa);
		}
		Matrix tmpmatr(N);
		mat.push_back(tmpmatr);

		dfs(i, 0, 0);
		
		
		for (int j = 0; j < N; j++) {
			mat[i].value[j][j] = 1;
		}
		
	}

	Matrix tt(N);
	tt = multi(mat[0], mat[1]);

	//for (int j = 0; j < N; j++) {
	//	for (int k = 0; k < N; k++) {
	//		cout << tt.value[j][k] << ' ';
	//	}
	//	cout << endl;
	//}

	return 0;
}