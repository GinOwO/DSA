// https://leetcode.com/problems/find-a-peak-element-ii/

#include <bits/stdc++.h>

using namespace std;

vector<int> findPeakGrid(vector<vector<int>>& matrix) { // T=O(n+m), S=O(1)
    int n = matrix.size(), m = matrix[0].size();
    int row = 0, col = m - 1, x;
    while ( row < n && col >= 0 ) {
        x = matrix[row][col];
        if ( row > 0 && matrix[row - 1][col] > matrix[row][col] ) row--;
        if ( row<n - 1 && matrix[row + 1][col]>matrix[row][col] ) row++;
        if ( col > 0 && matrix[row][col - 1] > matrix[row][col] ) col--;
        if ( col<m - 1 && matrix[row][col + 1]>matrix[row][col] ) col++;

        if ( x == matrix[row][col] ) return { row, col };
    }
    return { -1,-1 };
}

int main() {
    vector<vector<int>> matrix = { {25,37,23,37,19}, {45,19, 2,43,26}, {18, 1,37,44,50} };
    vector<int> ans = findPeakGrid(matrix);
    cout << ans[0] << ' ' << ans[1] << '\n';
}