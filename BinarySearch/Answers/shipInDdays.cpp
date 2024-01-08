// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

#include <bits/stdc++.h>

using namespace std;

unsigned helper(vector<int>& arr, int cap) {
    unsigned d = 0, tot = 0;
    for (auto& c : arr) {
        if (tot + c > cap) tot = 0, d++;
        tot += c;
    }
    return d;
}

int shipWithinDays(vector<int>& arr, int d) {
    int l = INT_MIN, r = 0, mid;
    for (auto& c : arr) {
        if (l < c) l = c;
        r += c;
    }

    while (l <= r) {
        mid = l + r >> 1;
        if (helper(arr, mid) >= d) l = mid + 1;
        else r = mid - 1;
    }
    return r + 1;
}

int main() {
    vector<int> arr = { 1,2,3,4,5,6,7,8,9,10 };
    cout << shipWithinDays(arr, 5) << '\n';
}