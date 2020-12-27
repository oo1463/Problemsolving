#include <algorithm>
#include <vector>

void bubble(int *arr){  // array sort
    for(int i=9; i>0; i--){
        for(int j = 0; j<i; j++){
            if(arr[j] > arr[j+1]){
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

void bubble(std::vector<int> &arr){  // vector sort
    for(int i = arr.size()-1; i>0; i--){
        for(int j = 0; j<i; j++){
            if(arr[j] > arr[j+1]){
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}