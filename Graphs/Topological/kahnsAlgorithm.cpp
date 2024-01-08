#include<bits/stdc++.h>

using namespace std;

/*
    Kahn's algorithm for topological sort.
    It is basically BFS instead of DFS.

    We find the in-degree of every node and push all nodes with in-degree 0 to a queue.
    This gives us the starting nodes for the topological sort, as these nodes have no dependencies and will appear at the front of the topological sort.

    We add all the nodes with in-degree 0 to the queue.

    We start the BFS, we pop the front of the queue and add it to the topological sort.
    We then reduce the in-degree of all its children by 1, if any of their in-degrees become 0, we add them to the queue.

    Once the queue is empty, we have the topological sort.

    Time complexity: O(V+E), Space complexity: O(V)
*/

class Solution {
public:
    vector<int> topoSort(vector<vector<int>>& adjList) {
        int n = adjList.size();
        vector<int> inDegree(n, 0), ans;
        queue<int> que;

        for (int i = 0; i < n; i++) {
            for (auto& v : adjList[i]) inDegree[v]++;
        }

        for (int i = 0; i < n; i++) {
            if (!inDegree[i]) que.push(i);
        }

        while (!que.empty()) {
            int curr = que.front();
            que.pop();
            ans.push_back(curr);

            for (auto& v : adjList[curr]) {
                if (--inDegree[v] == 0) que.push(v);
            }
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
    vector<int> stk = s.topoSort(adjList);

    for (auto& v : stk) cout << v << " ";
    cout << endl;

    return 0;
}