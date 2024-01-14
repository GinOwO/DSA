#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
    vector<int> parent, rank;

    int findParent(int node) {
        if ( parent[node] == node ) return node;
        return parent[node] = findParent(parent[node]);
    }

public:
    DisjointSet(int n) : parent(n + 1), rank(n + 1, 0) {
        for ( int i = 0; i <= n; i++ ) {
            parent[i] = i;
        }
    }

    void insertEdge(int u, int v) {
        int parentU = findParent(u);
        int parentV = findParent(v);

        if ( parentU == parentV ) return;

        if ( rank[parentU] < rank[parentV] ) {
            parent[parentU] = parentV;
        }
        else if ( rank[parentU] < rank[parentV] ) {
            parent[parentV] = parentU;
        }
        else {
            parent[parentV] = parentU;
            rank[parentU]++;
        }
    }

    bool isConnected(int u, int v) {
        return findParent(u) == findParent(v);
    }
};

int main(void) {
    int n = 5;
    DisjointSet ds(n);

    ds.insertEdge(1, 2);
    ds.insertEdge(2, 3);
    ds.insertEdge(4, 5);

    cout << ds.isConnected(1, 3) << endl;
    cout << ds.isConnected(1, 4) << endl;

    return 0;
}