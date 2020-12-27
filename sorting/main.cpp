#include <iostream>
#include "bubblesort.hpp"
#include <vector>
using namespace std;

int arr[10] = {1, 6, 3, 7, 2, 4, 5, 0, 9, 8};
vector<int> arr2;

int main(){
    bubble(arr);
    for(int i=0; i<10; i++){
        arr2.push_back(arr[i]);
    }

    bubble(arr2);

    for(auto a : arr2) {
        cout << a << ' ';
    }
}