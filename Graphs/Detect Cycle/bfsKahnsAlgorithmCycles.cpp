#include<bits/stdc++.h>

using namespace std;

/*
    We can use Kahn's algorithm to detect cycles in a graph.
    If the topological sort is not possible, then there is a cycle in the graph.
    This is because if there is a cycle, then there will be a node whose in-degree will not become 0 before the queue becomes empty.
    Hence, the topological sort will not be possible, i.e the size of the topo sort array will not be equal to the number of nodes in the graph.

    Time complexity: O(V+E), Space complexity: O(V)
*/

class Solution {
public:
    bool detectCyclesKahn(vector<vector<int>>& adjList) {
        int n = adjList.size();
        vector<int> inDegree(n, 0), ans;
        queue<int> que;

        for ( int i = 0; i < n; i++ ) {
            for ( auto& v : adjList[i] ) inDegree[v]++;
        }

        for ( int i = 0; i < n; i++ ) {
            if ( !inDegree[i] ) que.push(i);
        }

        while ( !que.empty() ) {
            int curr = que.front();
            que.pop();
            ans.push_back(curr);

            for ( auto& v : adjList[curr] ) {
                if ( --inDegree[v] == 0 ) que.push(v);
            }
        }

        return ans.size() != n;
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
    cout << s.detectCyclesKahn(adjList) << endl;
    return 0;
}