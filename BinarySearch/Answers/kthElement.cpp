// https://www.codingninjas.com/studio/problems/k-th-element-of-2-sorted-array_1164159

#include <bits/stdc++.h>

using namespace std;

int kthElement(vector<int>& arr1, vector<int>& arr2, int n1, int n2, int k) {
    if ( n1 > n2 ) return kthElement(arr2, arr1, n2, n1, k);

    int n = n1 + n2;
    int l = max(0, k - n2), r = min(k, n1), mid1, mid2;

    int l1, l2, r1, r2;

    while ( l <= r ) {
        mid1 = l + r >> 1;
        mid2 = k - mid1;
        l1 = l2 = INT_MIN;
        r1 = r2 = INT_MAX;
        if ( mid1 > 0 ) l1 = arr1[mid1 - 1];
        if ( mid2 > 0 ) l2 = arr2[mid2 - 1];
        if ( mid1 < n1 ) r1 = arr1[mid1];
        if ( mid2 < n2 ) r2 = arr2[mid2];

        if ( l1 <= r2 && l2 <= r1 ) return max(l1, l2);
        else if ( l1 > r2 ) r = mid1 - 1;
        else l = mid1 + 1;
    }
    return 0;
}

int main() {
    vector<int> arr1 = { 1,2,3,4,5,6,7,8,9,10 };
    vector<int> arr2 = { 11,12,13,14,15,16,17,18,19,20 };
    cout << kthElement(arr1, arr2, 10, 10, 10) << '\n';
}