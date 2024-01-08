#include <bits/stdc++.h>

using namespace std;

// Time complexity: O(V + E), Space complexity: O(V)

static int color[101];
class Solution {
public:
    bool dfs(const vector<vector<int>>& graph, int i, int prev, int color[]) {
        color[i] = prev;

        for (auto& v : graph[i]) {
            if (color[v] == -1) {
                if (!dfs(graph, v, !prev, color)) return false;
            }
            else if (color[v] == color[i]) {
                return false;
            }
        }
        return true;
    }

    bool bfs(const vector<vector<int>>& graph, int start, int color[]) {
        queue<int> que;
        que.push(start);
        color[start] = 0;

        while (!que.empty()) {
            int i = que.front();
            que.pop();

            for (auto& v : graph[i]) {
                if (color[v] == -1) {
                    color[v] = !color[i];
                    que.push(v);
                }
                else if (color[v] == color[i]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        memset(color, -1, sizeof(int) * 101);

        for (int i = 0; i < graph.size(); i++) {
            if (color[i] == -1) {
                if (!bfs(graph, i, color)) return false;
                // if(!dfs(graph, i, 0, color)) return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<int>> graph = { {1,3},{0,2},{1,3},{0,2} };
    cout << s.isBipartite(graph) << endl;
    return 0;
}