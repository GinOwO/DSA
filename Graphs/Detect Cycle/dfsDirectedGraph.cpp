#include <bits/stdc++.h>

using namespace std;

// Time complexity: O(V + E), Space complexity: O(V)

class Solution {
    bool dfs(const vector<vector<int>>& graph, int i, vector<int>& visited) {
        visited[i] = 2;

        for (auto& v : graph[i]) {
            if (visited[v] == 0) {
                if (dfs(graph, v, visited)) return true;
            }
            else if (visited[v] == 2) {
                return true;
            }
        }

        visited[i] = 1;
        return false;
    }

public:
    bool detectCycle(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                if (dfs(graph, i, visited)) return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<vector<int>>> testCasesAdjList = {
        {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}},
        {{1, 2, 3}, {2, 3}, {3}, {}},
        {{1}, {2}, {3}, {4}, {2}},
        {{1}, {2, 3}, {3, 4}, {4}, {0}}
    };

    vector<bool> answer = { true, false, true, true };

    for (int i = 0; i < testCasesAdjList.size(); i++) {
        cout << "Test case " << i + 1;
        assert(s.detectCycle(testCasesAdjList[i]) == answer[i]);
        cout << "\tPassed" << endl;
    }
    return 0;
}