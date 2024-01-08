// https://leetcode.com/problems/search-a-2d-matrix/

#include <bits/stdc++.h>

using namespace std;

bool searchRow(vector<int>& row, int m, int x) {
    int l = 0, r = m - 1, mid;
    while (l <= r) {
        mid = l + r >> 1;
        if (row[mid] == x) return 1;
        if (x < row[mid]) r = mid - 1;
        else l = mid + 1;
    }
    return 0;
}

bool searchMatrix(vector<vector<int>>& matrix, int x) {
    int l = 0, r = matrix.size() - 1, mid, m = matrix[0].size();

    while (l <= r) {
        mid = l + r >> 1;
        if (matrix[mid][0] <= x && x <= matrix[mid][m - 1]) {
            return searchRow(matrix[mid], m, x);
        }

        if (matrix[mid][0] > x) r = mid - 1;
        else l = mid + 1;
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,60} };
    cout << searchMatrix(matrix, 3) << '\n';
}