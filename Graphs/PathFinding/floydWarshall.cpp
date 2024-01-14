#include <bits/stdc++.h>

using namespace std;

/*
    Floyd-Warshall Algorithm: All pairs shortest path in a graph.
        Given a graph with n vertices represented as an adjacency matrix, find the shortest path between all pairs of vertices.
        This should be found in place, i.e. the adjacency matrix should be modified to contain the shortest paths.
        A -1 in the adjacency matrix represents no edge between the vertices.

        We convert -1 to 1e9 for easier implementation.
        Then we iterate through all the vertices and update the distances of the vertices.
        The distance of (i, j) will be the minimum of the distance of (i, j) and the sum of the distance of (i, k) and (k, j).
        We do this for all the vertices, then we convert 1e9 back to -1.

        If a negative cycle exists, then the distance of (i, i) will be negative.

        Time complexity: O(V^3), Space complexity: O(V^2)
*/

class Solution {
public:
    void floydWarshall(vector<vector<int>>& adjMatrix, int n) {
        // Convert -1, which represents no edge between them, to 1e9 for easier implementation
        for ( auto& row : adjMatrix ) {
            transform(row.begin(), row.end(), row.begin(),
                [](int a) { return a == -1 ? 1e9 : a; }
            );
        }

        for ( int k = 0; k < n; k++ ) {
            for ( int i = 0; i < n; i++ ) {
                for ( int j = 0; j < n; j++ ) {
                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
                }
            }
        }

        // Convert 1e9 which represents no path back to -1
        for ( auto& row : adjMatrix ) {
            transform(row.begin(), row.end(), row.begin(),
                [](int a) { return a == 1e9 ? -1 : a; }
            );
        }
    }
};

int main(void) {
    vector<vector<int>> adjMatrix = {
        {0, 3, -1, 7},
        {8, 0, 2, -1},
        {5, -1, 0, 1},
        {2, -1, -1, 0}
    };
    int n = adjMatrix.size();

    Solution().floydWarshall(adjMatrix, n);

    for ( auto& row : adjMatrix ) {
        for ( auto& col : row ) {
            cout << col << " ";
        }
        cout << endl;
    }

    return 0;
}