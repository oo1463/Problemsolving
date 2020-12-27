#include <iostream>
#include "bubblesort.hpp"
#include "selectionsort.hpp"
#include <vector>
using namespace std;

int arr[10] = {1, 6, 3, 7, 2, 4, 5, 0, 9, 8};
vector<int> arr2;

void print_arr(int *arr){
    for(int i=0; i<10; i++) cout << arr[i] << ' ';
    cout << endl;
}

int main(){

    cout << "Before sort array : ";
    print_arr(arr);
    // bubble(arr);
    // for(int i=0; i<10; i++){
    //     arr2.push_back(arr[i]);
    // }

    // bubble(arr2);

    selection(arr);

    cout << "After sort array : ";
    for(auto a : arr) {
        cout << a << ' ';
    }
}