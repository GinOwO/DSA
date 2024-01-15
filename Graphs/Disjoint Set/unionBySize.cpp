#include <bits/stdc++.h>

using namespace std;

/*
    Disjoint Set Union by Size: A data structure that keeps track of a set of elements partitioned into a number of disjoint subsets.
        It supports two operations:
            Find: Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.
            Union: Join two subsets into a single subset.

        We use an array to keep track of the parent of each node. Initially each node is its own parent.
        We also keep track of the size of each node. Initially each node has a size of 1.

        When we join two subsets, we make the parent of the subset with the smaller size the parent of the other subset.
        If both the subsets have the same size, then we arbitrarily choose one subset to be the parent of the other subset.
        In both cases we add the size of the smaller subset to the size of the larger subset.

        To check if two elements are in the same subset, we check if their parents are the same.

        Time complexity: O(4*α(n)), Space complexity: O(n)
            where α(n) is the inverse Ackermann function, which grows very slowly and is less than 5 for all practical values of n.
            This is the amortized time complexity. This is better than O(logn). This TC is because we use path compression.
*/

class DisjointSetSize {
    vector<int> parent, size;
public:
    DisjointSetSize(int n) : parent(n + 1), size(n + 1, 1) {
        for ( int i = 0; i <= n; i++ ) {
            parent[i] = i;
        }
    }

    void insertEdge(int u, int v) {
        int parentU = findParent(u);
        int parentV = findParent(v);

        if ( parentU == parentV ) return;

        if ( size[parentU] < size[parentV] ) {
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
        else {
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
    }

    bool isConnected(int u, int v) {
        return findParent(u) == findParent(v);
    }

    int findParent(int node) {
        if ( parent[node] == node ) return node;
        return parent[node] = findParent(parent[node]);
    }

    int findSize(int node) {
        return size[findParent(node)];
    }
};

int main(void) {
    int n = 5;
    DisjointSetSize ds(n);

    ds.insertEdge(1, 2);
    ds.insertEdge(2, 3);
    ds.insertEdge(4, 5);

    cout << ds.isConnected(1, 3) << endl;
    cout << ds.isConnected(1, 4) << endl;

    return 0;
}