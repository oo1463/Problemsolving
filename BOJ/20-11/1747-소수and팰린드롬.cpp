// https://www.acmicpc.net/problem/1747

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define el '\n'
#define FAIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

using namespace std;

int n;
bool prime[1004001];

void findPrime(int n) {

    for (long long i = 2; i <= 1004000; i++) {
        if (prime[i]) {
            for (long long j = i * i; j <= 1004000; j = j + i) {
                prime[j] = false;
            }
        }
    }

}

bool isPalindrom(int num) {
    string numString = to_string(num);
    int len = numString.length();
    for (int i = 0; i <= len / 2; i++) if (numString[i] != numString[len - i - 1]) return false;
    return true;
}


int main() {
    FAIO;

    cin >> n;

    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    prime[2] = true;

    findPrime(n);

    for (int i = n; i <= 1004000; i++) {
        if (prime[i] == true) {
            if (isPalindrom(i)) {
                cout << i;
                break;
            }
        }
    }
    return 0;
}


/*
    Algorithm : string, eratosthenes sieve
    Time complexity : O(nloglogn)

*/