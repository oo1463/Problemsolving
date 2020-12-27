#include <algorithm>
#include <vector>

void selection(int *arr){  // array sort
    for(int i=0; i<9; i++){
        int mn = arr[i];
        int min_index = i;
        for(int j=i; j<10; j++){
            if(mn > arr[j]) {
                mn = arr[j];
                min_index = j; 
            }
        }
        std::swap(arr[i], arr[min_index]);
    }
}
