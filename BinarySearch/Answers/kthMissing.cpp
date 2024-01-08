// https://leetcode.com/problems/kth-missing-positive-number/

#include<bits/stdc++.h>

using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int l = 0, r = arr.size() - 1, mid;
    while (l <= r) {
        mid = l + r >> 1;
        if (arr[mid] - mid - 1 >= k) r = mid - 1;
        else l = mid + 1;
    }
    return l + k;
}

int main() {
    vector<int> arr = { 2,3,4,7,11 };
    cout << findKthPositive(arr, 5) << '\n';
}