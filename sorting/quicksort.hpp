#include <algorithm>
#include <vector>
#include <iostream>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick_sort(int *arr, int start, int end){  

    if(start >= end) return;

    int pivot = start;

    int i = start + 1;
    int j = end;

    while(i<=j){
        while(arr[i] < arr[pivot]) i++;
        while(arr[j] > arr[pivot]) j--;
        if(i>j) {
            swap(&arr[pivot], &arr[j]);
            break;
        }

        swap(&arr[i], &arr[j]);

    }
    
    quick_sort(arr, start, j-1);
    quick_sort(arr, j+1, end);

}