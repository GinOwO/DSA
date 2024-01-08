#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<climits>

using namespace std;

class Graph { // Directed
    vector<vector<pair<int, int>>> adj;
    int size;

    void path(vector<int>& v, int n) {
        if (v[n] == -1) cout << n;
        else {
            path(v, v[n]);
            cout << " -> " << n;
        }
    }

public:
    Graph(vector<vector<int>>& edges) {
        adj.reserve(size = edges.size());
        for (auto& v : edges) addEdge(v);
    }

    void addEdge(vector<int>& v) {
        adj[v[0]].push_back({ v[1],v[2] });
    }

    void find(int n1, int n2) {
        int n;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({ 0,n1 });

        vector<int> visited(size, 0);
        vector<int> dist(size, INT_MAX);
        vector<int> prev(size, -1);
        dist[n1] = 0;

        while (!q.empty()) {
            n = q.top().second; q.pop();
            if (visited[n]) continue;
            visited[n] = 1;

            for (auto& v : adj[n]) {
                int d = dist[n] + v.second;
                if (d < dist[v.first]) {
                    dist[v.first] = d;
                    prev[v.first] = n;
                    q.push({ d,v.first });
                }
            }
        }
        if (dist[n2] == INT_MAX) {
            cout << "No path found" << endl;
            return;
        }
        cout << "Distance: " << dist[n2] << endl;
        cout << "Path: "; path(prev, n2); cout << endl;
    }
};


int main() {
    vector<vector<int>> edges = { {0,1,4},{0,7,8},{1,2,8},{1,7,11},{2,3,7},{2,8,2},{2,5,4},{3,4,9},{3,5,14},{4,5,10},{5,6,2},{6,7,1},{6,8,6},{7,8,7} };
    Graph g(edges);
    g.find(0, 6);
    return 0;
}