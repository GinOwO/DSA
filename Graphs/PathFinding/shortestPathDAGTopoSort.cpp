#include <bits/stdc++.h>

using namespace std;

/*
    Single source shortest path in a DAG with topological sort.
    Works for negative weights but not for cycles.

    We first do a topological sort and then relax the edges in the order of the topological sort.

    Time complexity: O(V+E), Space complexity: O(V)
*/

class Solution {
    void dfs(vector<vector<pair<int, int>>>& graph, vector<bool>& visited, stack<int>& stk, int start) {
        visited[start] = 1;
        for ( auto& [v, _] : graph[start] ) {
            if ( !visited[v] ) dfs(graph, visited, stk, v);
        }
        stk.push(start);
    }

public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n, int start) {
        vector<vector<pair<int, int>>> adjList(n);
        vector<bool> visited(n, 0);
        vector<int> dist(n, 1e9);
        stack<int> stk;

        for ( auto& edge : edges ) {
            adjList[edge[0]].push_back({ edge[1], edge[2] });
        }


        for ( int i = 0; i < n; i++ ) {
            if ( !visited[i] ) dfs(adjList, visited, stk, i);
        }

        dist[start] = 0;
        while ( !stk.empty() ) {
            int node = stk.top();
            stk.pop();

            for ( auto& [v, w] : adjList[node] ) {
                if ( dist[node] + w < dist[v] ) {
                    dist[v] = dist[node] + w;
                }
            }
        }

        transform(dist.begin(), dist.end(), dist.begin(), [](int x) { return x == 1e9 ? -1 : x; });
        return dist;
    }
};

int main() {
    vector<vector<int>> edges = {
        {0,1,3},
        {0,2,6},
        {1,2,4},
        {1,3,4},
        {1,4,11},
        {2,3,8},
        {2,6,11},
        {3,4,-4},
        {3,5,5},
        {3,6,2},
        {4,7,9},
        {5,7,1},
        {6,7,2},
        {7,8,0}
    };
    Solution s;
    vector<int> dist = s.shortestPath(edges, 9, 0);
    for ( auto& v : dist ) cout << v << " ";
    cout << endl;
}