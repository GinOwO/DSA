// https://www.codingninjas.com/studio/problems/row-of-a-matrix-with-maximum-ones_982768

#include <bits/stdc++.h>

using namespace std;

int helper(vector<int>& row, int m) {
    int l = 0, r = m, mid;
    while (l <= r) {
        mid = l + r >> 1;
        if (row[mid] >= 1) r = mid - 1;
        else l = mid + 1;
    }
    return r + 1;
}

int rowWithMax1s(vector<vector<int>>& arr, int n, int m) {
    int ans = -1, mx = 0;
    for (int i = 0; i < n; i++) {
        int cnt = m - helper(arr[i], m);
        if (cnt > mx) mx = cnt, ans = i;
    }
    return ans;
}

int main() {
    vector<vector<int>> arr = { {0,0,0,1},{0,1,1,1},{1,1,1,1},{0,0,0,0} };
    cout << rowWithMax1s(arr, 4, 4) << '\n';
}