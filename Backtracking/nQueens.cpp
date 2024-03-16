#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs( int m, const int n, vector<int>&& path, vector<vector<bool>>& disallowed, vector<vector<int>>& ans ) {
        if ( n < 4 ) {
            if ( n == 1 ) {
                ans.push_back( { 1 } );
            }
            return;
        }
        if ( m > n ) {
            ans.push_back( path );
            return;
        }

        for ( int i = 1; i <= n; i++ ) {
            if ( !disallowed [ 0 ][ i ] && !disallowed [ 1 ][ n + ( m - i ) ] && !disallowed [ 2 ][ m + i ] ) {
                path.push_back( i );
                disallowed [ 0 ][ i ] = disallowed [ 1 ][ n + ( m - i ) ] = disallowed [ 2 ][ m + i ] = 1;
                dfs( m + 1, n, move( path ), disallowed, ans );
                disallowed [ 0 ][ i ] = disallowed [ 1 ][ n + ( m - i ) ] = disallowed [ 2 ][ m + i ] = 0;
                path.pop_back( );
            }
        }
    }

    vector<vector<int>> nQueen( int n ) {
        vector<int> path;
        vector<vector<int>> ans;
        vector<vector<bool>> disallowed( 3, vector<bool>( 2 * n + 1, 0 ) );

        dfs( 1, n, move( path ), disallowed, ans );
        return ans;
    }
};

int main( ) {
    Solution s;
    vector<vector<int>> ans = s.nQueen( 4 );
    for ( auto& v : ans ) {
        for ( auto& i : v ) cout << i << " ";
        cout << endl;
    }
    return 0;
}