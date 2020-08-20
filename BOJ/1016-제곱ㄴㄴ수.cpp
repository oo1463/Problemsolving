// https://www.acmicpc.net/problem/1016

//시간제한  메모리
//2 초	    512 MB

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 1000001
using namespace std;

vector<long long> vec;
int arr[MAX];

void getChe() {
    long long i;

    for (i = 2; i < MAX; i++) {
        arr[i] = 1;
    }

    for (i = 2; i < MAX; i++) {
        if (arr[i] == 0)
            continue;

        for (long long j = i + i; j < MAX; j += i) {
            arr[j] = 0;
        }
        vec.push_back(i*i);
    }
}

bool visited[MAX];


int main() {

    long long min, max;
    int j, count = 0;


    cin >> min >> max;

    getChe();
    
    int len = vec.size();
    
    for (int i = 0; i < MAX; i++) visited[i] = false;
    
    for (j = 0; j < len; j++) {
        if (vec[j] > max) break;
        long long x = min / vec[j];
        if (min % vec[j] != 0) x++;

        while (x * vec[j] <= max) {
            visited[x * vec[j] - min] = true;
            x++;
        }
    }

    for (int i = 0; i <= max - min; i++) if (visited[i]) count++;
   
    cout << max - min + 1 - count;

    return 0;
}


/*
    Algorithm : eratos thenes

    Time complexity : O(max-min)

*/