#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100001

int arr[MAX + 1];

void getChe() {
    int i;
    
    for (i = 2; i <= MAX; i++) {
        arr[i] = 1;
    }

    for (i = 2; i <= MAX; i++) {
        if (arr[i] == 0)
            continue;

        for (int j = i + i; j <= MAX; j += i) {
            arr[j] = 0;
        }
    }
}

int main() {

    int input;
    int flag;
    getChe();

    while (1) {        
        cin >> input;
        if (input == 0) return 0;
        
        flag = 0;
        for (int i = 3; i <= input / 2; i++) {
            if (arr[i] == 1 && arr[input-i] == 1) {
                cout << input << " = " << i << " + " << input-i << '\n';
                flag = 1;
                break;
            }                
        }
        if (flag == 0) cout << "Goldbach's conjecture is wrong." << endl;
        flag = 0;
        
    }

	return 0;
}


/*
    Algorithm : eratosthenes sieve  - O(nloglogn)

    Time complexity : O(nloglogn)
    
*/