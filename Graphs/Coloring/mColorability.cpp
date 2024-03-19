#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool dfs( int i, const vector<vector<int>>& graph, vector<int>& color, int prev, int m ) {
        color [ i ] = prev;
        for ( auto& v : graph [ i ] ) {
            if ( color [ v ] == -1 ) {
                if ( !dfs( v, graph, color, ( prev + 1 ) % m, m ) ) return false;
            }
            else if ( color [ v ] == color [ i ] ) {
                return false;
            }
        }
        return true;
    }

    bool bfs( int start, const vector<vector<int>>& graph, vector<int>& color, int m ) {
        queue<int> que;
        que.push( start );
        color [ start ] = 0;

        while ( !que.empty( ) ) {
            int i = que.front( );
            que.pop( );

            for ( auto& v : graph [ i ] ) {
                if ( color [ v ] == -1 ) {
                    color [ v ] = ( color [ i ] + 1 ) % m;
                    que.push( v );
                }
                else if ( color [ v ] == color [ i ] ) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isMColorable( const vector<vector<int>>& graph, int m ) {
        int n = graph.size( );
        vector<int> color( n, -1 );
        for ( int i = 0; i < n; i++ ) {
            if ( color [ i ] == -1 ) {
                if ( !dfs( i, graph, color, 0, m ) ) return false;
            }
        }
        return true;
    }

};

int main( ) {
    Solution solution;
    vector<vector<int>> adjList = {
        { 1, 3 },
        { 0, 2 },
        { 1, 3 },
        { 0, 2 }
    };

    cout << solution.isMColorable( adjList, 2 ) << endl;

    return 0;
}