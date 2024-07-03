#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Point;

#define dist( p1, p2 ) ( \
    ( p1.first - p2.first ) * ( p1.first - p2.first ) + \
    ( p1.second - p2.second ) * ( p1.second - p2.second ) \
)

Point nextToTop( stack<Point>& S ) {
    Point p = S.top( ); S.pop( );
    Point res = S.top( ); S.push( p );
    return res;
}

int dir( const Point& p, const Point& q, const Point& r ) {
    int val = ( q.second - p.second ) * ( r.first - q.first ) -
        ( q.first - p.first ) * ( r.second - q.second );

    if ( val == 0 ) return 0;
    return ( val > 0 ) ? 1 : 2;
}

void convexHull( vector<Point>& points, int n ) {
    int ymin = points [ 0 ].second, min = 0;
    for ( int i = 1; i < n; i++ ) {
        int y = points [ i ].second;
        if ( ( y < ymin ) || ( ymin == y &&
            points [ i ].first < points [ min ].first ) )
            ymin = points [ i ].second, min = i;
    }

    swap( points [ 0 ], points [ min ] );

    sort( points.begin( ) + 1, points.end( ), [ &points ]( Point& p1, Point& p2 ) {
        int o = dir( points [ 0 ], p1, p2 );
        return ( o == 0 ? dist( points [ 0 ], p2 ) >= dist( points [ 0 ], p1 ) : o == 2 );
    } );

    int m = 1;
    for ( int i = 1; i < n; i++ ) {
        while ( i < n - 1 && dir( points [ 0 ], points [ i ], points [ i + 1 ] ) == 0 ) i++;
        points [ m++ ] = points [ i ];
    }

    if ( m < 3 ) return;

    stack<Point> S;
    S.push( points [ 0 ] );
    S.push( points [ 1 ] );
    S.push( points [ 2 ] );

    for ( int i = 3; i < m; i++ ) {
        while ( S.size( ) > 1 && dir( nextToTop( S ), S.top( ), points [ i ] ) != 2 )
            S.pop( );
        S.push( points [ i ] );
    }

    while ( !S.empty( ) ) {
        Point p = S.top( );
        cout << "(" << p.first << ", " << p.second << ")" << endl;
        S.pop( );
    }
}

int main( ) {
    int n; cin >> n;
    vector<Point> points( n );
    for ( auto& [x, y] : points ) cin >> x >> y;
    convexHull( points, n );
    return 0;
}