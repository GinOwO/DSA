// https://www.spoj.com/problems/AGGRCOW/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void solve();

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}

bool helper(vector<int>& arr, int d, int c) {
    int p = arr[0] - d;
    for (auto& q : arr) {
        if (q - p >= d) c--, p = q;
        if (c <= 0) return 1;
    }
    return 0;
}

void solve() {
    int n, c; cin >> n >> c;
    vector<int> arr(n);
    for (auto& c : arr) cin >> c;
    sort(arr.begin(), arr.end());

    unsigned l = 1, r = arr[n - 1] - arr[0], mid;
    while (l <= r) {
        mid = l + r >> 1;
        if (helper(arr, mid, c)) l = mid + 1;
        else r = mid - 1;
    }
    cout << r << '\n';
}