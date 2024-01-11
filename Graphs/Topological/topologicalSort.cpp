#include<bits/stdc++.h>

using namespace std;

/*
    Topological sort is only possible in a Directed Acyclic Graph (DAG).
    Topological sort is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering.
    Topological sort is not unique.

    We just do a DFS on every unvisited node and push it to the stack once all its children have been visited.
    The stack is popped into ans to get the topological sort.

    Technically instead of a stack we can use a vector and just reverse it at the end.

    Time complexity: O(V+E), Space complexity: O(V)
*/

class Solution {
    void dfs(vector<vector<int>>& graph, vector<int>& visited, stack<int>& stk, int start) {
        visited[start] = 1;
        for ( auto& v : graph[start] ) {
            if ( !visited[v] ) dfs(graph, visited, stk, v);
        }
        stk.push(start);
    }

public:
    vector<int> topologicalSort(vector<vector<int>>& adjList) {
        int n = adjList.size();
        stack<int> stk;
        vector<int> visited(n, 0);

        for ( int i = 0; i < n; i++ ) {
            if ( !visited[i] ) dfs(adjList, visited, stk, i);
        }

        vector<int> ans;
        while ( !stk.empty() ) {
            ans.push_back(stk.top());
            stk.pop();
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> adjList = {
        {1,3},
        {2},
        {3},
        {4},
        {5},
        {}
    };

    Solution s;
    vector<int> stk = s.topologicalSort(adjList);

    for ( auto& v : stk ) cout << v << " ";
    cout << endl;

    return 0;
}