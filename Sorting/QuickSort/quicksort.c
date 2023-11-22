#include<stdio.h>

#define swap(a, b) {int t=a; a=b; b=t;}
#define REP(n) for(int i=0; i<n; i++)

void quicksort(int*, int, int);
int partition(int*, int, int);

int main(){
    int n; scanf("%d", &n); int arr[n]; 
    REP(n) scanf("%d", arr+i);
    quicksort(arr,0,n-1);
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    puts("");
    return 0;
}

void quicksort(int* arr, int l, int r){
    if(l<r){
        int q=partition(arr, l, r);
        quicksort(arr,l,q);
        quicksort(arr,q+1,r);
    }
}

int partition(int* arr, int l, int r){
    int pi = l; l--; r++;
    while(1){
        do l++; while(arr[l]<arr[pi]);
        do r--; while(arr[r]>arr[pi]);
        if(l>=r) return r;
        else swap(arr[l], arr[r]);
    }
}