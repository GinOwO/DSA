// https://www.codingninjas.com/studio/problems/rotation_7449070
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <bits/stdc++.h>

using namespace std;

int findKRotation(vector<int>& arr) {
    int l = 0, r = arr.size() - 1, mid, ans = 0;
    while ( l <= r ) {
        mid = l + r >> 1;
        if ( arr[l] <= arr[r] ) {
            int q = ( arr[l] < arr[ans] ? l : mid );
            return ( arr[q] < arr[ans] ? q : ans );
        }

        if ( arr[l] <= arr[mid] ) {
            ans = ( arr[l] < arr[ans] ? l : ans );
            l = mid + 1;
        }
        else {
            ans = ( arr[mid] < arr[ans] ? mid : ans );
            r = mid - 1;
        }
    }
    return 0;
}

int main() {
    vector<int> arr = { 4,5,6,7,0,1,2 };
    cout << findKRotation(arr) << '\n';
}