#include<stdio.h>

void insertion_sort(int* arr, const int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i]; j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
