#include <bits/stdc++.h>

using namespace std;

vector<int> makePrefix( const string& pattern ) {
    int n = pattern.size( );
    vector<int> prefix( n, 0 );

    for ( int i = 1, j = 0; i < n; i++ ) {
        while ( j > 0 && pattern [ i ] != pattern [ j ] ) {
            j = prefix [ j - 1 ];
        }
        if ( pattern [ i ] == pattern [ j ] ) {
            j++;
        }
        prefix [ i ] = j;
    }

    return prefix;
}

int KMPsearch( const string& text, const string& pattern ) {
    int n = text.size( );
    int m = pattern.size( );
    vector<int> prefix = makePrefix( pattern );

    for ( int i = 0, j = 0; i < n; i++ ) {
        while ( j > 0 && text [ i ] != pattern [ j ] ) {
            j = prefix [ j - 1 ];
        }
        if ( text [ i ] == pattern [ j ] ) {
            j++;
        }
        if ( j == m ) {
            return i - m + 1;
        }
    }

    return -1;
}

int main( ) {
    string text = "AXABAACAADAABAABA";
    string pattern = "AABA";
    cout << KMPsearch( text, pattern ) << endl;
    return 0;
}