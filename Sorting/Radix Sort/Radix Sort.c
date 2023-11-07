#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void radixSort(int* arr, int n, int k){
    if(c==0) return;
    int* bucket[10][0];
    for(int i=0;i<10;i++)
        for(int j=0;j<n;j++) bucket[i][j]=-1;
    
    for(int i=0; i<n; i++)
}

int main(){
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}, m, i;
    for(m=arr[0], i=0; i<11; i++) if(arr[i]>m) m=arr[i];
    radixSort(arr,sizeof(arr)/sizeof(arr[0]), 0);
    for(int i=0; i<11; i++) printf("%d ", arr[i]);
    return 0;
}