
// https://www.acmicpc.net/problem/1016

//시간제한  메모리
//2 초	    512 MB

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001
using namespace std;

vector<long long> vec;
int arr[MAX];
int fi[1000001];


void getChe() {
    long long i;

    for (i = 2; i < MAX; i++) {
        arr[i] = 1;
    }

    for (i = 2; i < MAX; i++) {
        if (arr[i] == 0)
            continue;

        for (int j = i + i; j < MAX; j += i) {
            arr[j] = 0;
        }
        
        vec.push_back(i*i);
    }

    
}

int main() {

    long long i;
    long long min, max;
    int j, count = 0;


    cin >> min >> max;

    getChe();

    int len = vec.size();

    for (i = min; i <= max; i++) {
        for (j = 0; j < len && max >= vec[j]; j++) {
            if (i % vec[j] == 0) {
                count++;
                break;
            }
        }
    }
    

    cout << max - min +1 - count;

    return 0;
}


/*
    Algorithm :

    Time complexity :

*/