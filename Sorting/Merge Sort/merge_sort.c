#include<stdio.h>

#define REP(n) for(int i=0;i<n;i++)

void merge(int* arr, int l, int m, int r) {
    int L[m - l + 1], R[r - m], i = 0, j = 0, k = l;
    REP(m - l + 1) L[i] = arr[l + i];
    REP(r - m) R[i] = arr[m + i + 1];

    while (i < m - l + 1 && j < r - m) arr[k++] = (L[i] < R[j] ? L[i++] : R[j++]);
    while (i < m - l + 1) arr[k++] = L[i++];
    while (j < r - m) arr[k++] = R[j++];
}

void mergesort(int* arr, int l, int r) {
    if (r <= l)return;
    int m = (l + r) / 2;
    mergesort(arr, l, m);
    mergesort(arr, m + 1, r);

    merge(arr, l, m, r);
}

int main() {
    int arr[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    mergesort(arr, 0, 10);
    for (int i = 0; i < 11; i++) printf("%d ", arr[i]);
    return 0;
}

