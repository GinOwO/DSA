#include<stdio.h>

int lb(int* arr, int n, int x) {
    int l = 0, r = n - 1, mid;
    while ( l <= r ) {
        mid = ( l + r ) / 2;
        if ( arr[mid] >= x ) r = mid - 1;
        else l = mid + 1;
    }
    return r + 1;
}

int ub(int* arr, int n, int x) {
    int l = 0, r = n - 1, mid;
    while ( l <= r ) {
        mid = ( l + r ) / 2;
        if ( arr[mid] > x ) r = mid - 1;
        else l = mid + 1;
    }
    return r + 1;
}

int main() {
    int arr[] = { 5,7,7,8,8,8,10 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int l = lb(arr, n, 8),
        r = ub(arr, n, 8);

    if ( l >= n || l < 0 ) puts("-1\t-1\t0");
    else printf("LB: %d\tUB: %d\tCount: %d\n", l, r, r - l);
    return 0;
}