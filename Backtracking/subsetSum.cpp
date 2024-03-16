#include <bits/stdc++.h>

using namespace std;

class Solution {
    void dfs( int i, const int target, const vector<int>& arr, vector<int>&& path, vector<vector<int>>& ans ) {
        if ( i == arr.size( ) ) {
            if ( target == 0 ) ans.push_back( path );
            return;
        }

        if ( arr [ i ] <= target ) {
            path.push_back( arr [ i ] );
            dfs( i + 1, target - arr [ i ], arr, move( path ), ans );
            path.pop_back( );
        }

        dfs( i + 1, target, arr, move( path ), ans );
    }

public:
    vector<vector<int>> subsetSum( const vector<int>& arr, int target ) {
        vector<int> path;
        vector<vector<int>> ans;
        dfs( 0, target, arr, move( path ), ans );
        return ans;
    }
};

int main( ) {
    Solution s;
    vector<vector<int>> ans = s.subsetSum( { 1, 2, 3, 4, 5 }, 10 );
    for ( auto& v : ans ) {
        for ( auto& i : v ) cout << i << " ";
        cout << endl;
    }
    return 0;
}