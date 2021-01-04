#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

long long factorial(int n){
    long long fac = 1;
    for(long long i=1; i<=n; i++){
        fac*=i;
    }

    return fac;
}

int main() {
    FAIO;

    int m,n;
    cin >> m >> n;

    cout << factorial(n) * pow(n, m-n);
   
    return 0;
}
