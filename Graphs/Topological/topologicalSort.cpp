#include<bits/stdc++.h>

using namespace std;

/*
    Topological sort is only possible in a Directed Acyclic Graph (DAG)
    Topological sort is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering
    Topological sort is not unique

    Time complexity: O(V+E), Space complexity: O(V)
*/

class Solution {
    void dfs(vector<vector<int>>& graph, vector<int>& visited, vector<int>& ans, int start) {
        visited[start] = 1;
        for (auto& v : graph[start]) {
            if (!visited[v]) dfs(graph, visited, ans, v);
        }
        ans.push_back(start);
    }

public:
    vector<int> topologicalSort(vector<vector<int>>& adjList) {
        int n = adjList.size();
        vector<int> ans;
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) dfs(adjList, visited, ans, i);
        }

        reverse(ans.begin(), ans.end());

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
        {1}
    };

    Solution s;
    vector<int> ans = s.topologicalSort(adjList);

    for (auto& v : ans) cout << v << " ";
    cout << endl;

    return 0;
}