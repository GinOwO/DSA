#include <bits/stdc++.h>

using namespace std;

constexpr unsigned long long PRIME = 23;
constexpr unsigned long long MOD = 1e9 + 7;

size_t rabinKarp( const string& text, const string& pattern ) {
    size_t n = text.size( ), m = pattern.size( );
    unsigned long long patternHash = 0, textHash = 0;

    for ( unsigned long long i = 0; i < m; i++ ) {
        patternHash = ( ( patternHash * PRIME ) + pattern [ i ] ) % MOD;
        textHash = ( ( textHash * PRIME ) + text [ i ] ) % MOD;
    }

    const unsigned long long po = pow( PRIME, m - 1 );

    for ( unsigned long long i = 0; i <= n - m; i++ ) {
        if ( patternHash == textHash ) {
            for ( unsigned long long j = 0; j < m; j++ ) {
                if ( text [ i + j ] != pattern [ j ] ) {
                    break;
                }

                if ( j == m - 1 ) {
                    return i;
                }
            }
        }

        textHash = ( ( textHash - text [ i ] * po ) * PRIME + text [ i + m ] ) % MOD;
    }

    return -1;
}

int main( ) {
    string text = "AXABAACAADAABAABA";
    string pattern = "AABA";
    cout << rabinKarp( text, pattern ) << endl;
    return 0;
}