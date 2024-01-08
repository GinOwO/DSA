// https://leetcode.com/problems/search-a-2d-matrix-ii/

#include <bits/stdc++.h>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int x) {
    int n = matrix.size();
    int row = 0, col = matrix[0].size() - 1;
    while (row < n && col >= 0) {
        if (matrix[row][col] == x) return 1;
        if (matrix[row][col] > x) col--;
        else row++;
    }
    return 0;
}

int main() {
    vector<vector<int>> matrix = { {1,3,5,7},{10,11,16,20},{23,30,34,60} };
    cout << searchMatrix(matrix, 3) << '\n';
}