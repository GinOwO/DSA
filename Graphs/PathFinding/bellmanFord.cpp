#include <bits/stdc++.h>

using namespace std;

/*
    Bellman-Ford Algorithm: Single source shortest path in a graph with negative edges.
        Dijkstra's algorithm will turn into an infinite loop if there is a negative cycle in the graph.
        Bellman-Ford algorithm can detect negative cycles and not enter an infinite loop, but whereas Dijkstra's algorithm
            has a time complexity of O(ElogV), Bellman-Ford algorithm has a time complexity of O(|V|*|E|). In the worst case
            when all the vertices are connected to each other, the time complexity will be O(V^3).

        We use a distance array to keep track of the distances from the source to all the other vertices.
        Initially set all its values to infinity, except the source vertex which is set to 0.
        Then we iterate through all the edges and update the distances of the vertices.
        We need to do this for n-1 times, where n is the number of vertices in the graph.
        Every time it will update the distances of the vertices if it finds a shorter path.
        After the n-1 iterations, we again try updating the distances of the vertices, but this time if it decreases,
            it means there is a negative cycle in the graph. Hence we return {-1} to indicate it.
        Else we return the distances.


        Time complexity: O(|V|*|E|), Space complexity: O(V)

        Note: We are checking for dist[u] != 1e9 because if the distance is 1e9, it means that the vertex has
            not been visited yet. If we don't check for this, then we will get a wrong answer as if the distance
            to be added is negative, then it will update the distance of the next vertex even if no path from
            source to current vertex exists.
*/

class Solution {
public:
    vector<int> bellman_ford(const vector<vector<int>>& edges, int n, int src) {
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // Calculate the distances for n-1 times
        for ( int i = 1; i < n; i++ ) {
            for ( auto& edge : edges ) {
                int u = edge[0], v = edge[1], w = edge[2];
                if ( dist[u] != 1e9 && dist[u] + w < dist[v] ) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Check if there is a negative cycle, if yes return { -1 } to indicate it.
        for ( auto& edge : edges ) {
            int u = edge[0], v = edge[1], w = edge[2];
            if ( dist[u] != 1e9 && dist[u] + w < dist[v] ) {
                return { -1 };
            }
        }

        // Else return the distances
        return dist;
    }
};

int main(void) {
    vector<vector<int>> edges = {
        { 0,1,1 },
        { 0,2,5 },
        { 1,2,3 },
        { 1,3,7 },
        { 2,3,1 },
        { 3,4,2 },
        { 3,5,1 },
        { 4,5,2 },
        { 4,6,3 },
        { 5,6,3 }
    };
    int n = 7, src = 0;

    Solution s;
    vector<int> dist = s.bellman_ford(edges, n, src);

    for ( int i = 0; i < n; i++ ) {
        cout << "Distance from " << src << " to " << i << " is " << dist[i] << endl;
    }

    return 0;
}