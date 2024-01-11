// https://leetcode.com/problems/split-array-largest-sum/description/

#include <bits/stdc++.h>

using namespace std;

bool helper(const vector<int>& arr, int mx, int k) {
    unsigned total = 0;
    for ( auto& c : arr ) {
        if ( total + c > mx ) total = 0, k--;
        if ( k <= 0 ) return 1;
        total += c;
    }
    return 0;
}

int splitArray(const vector<int>& arr, int k) {
    int l = INT_MIN, r = 0, mid;

    for ( auto& c : arr ) {
        if ( l < c ) l = c;
        r += c;
    }

    while ( l <= r ) {
        mid = l + r >> 1;
        if ( helper(arr, mid, k) ) l = mid + 1;
        else r = mid - 1;
    }
    return r + 1;
}

int main() {
    cout << splitArray({ 7,2,5,10,8 }, 2) << '\n';
}