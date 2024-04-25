#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Point;

bool onSegment( const Point& p, const Point& q, const Point& r ) {
    return q.first <= max( p.first, r.first ) && q.first >= min( p.first, r.first ) &&
        q.second <= max( p.second, r.second ) && q.second >= min( p.second, r.second );
}

int orientation( const Point& p, const Point& q, const Point& r ) {
    int val = ( q.second - p.second ) * ( r.first - q.first ) - ( q.first - p.first ) * ( r.second - q.second );
    if ( val == 0 ) return 0;
    return ( val > 0 ) ? 1 : 2;
}

bool intersect( const Point& p1, const Point& q1, const Point& p2, const Point& q2 ) {
    int o1 = orientation( p1, q1, p2 );
    int o2 = orientation( p1, q1, q2 );
    int o3 = orientation( p2, q2, p1 );
    int o4 = orientation( p2, q2, q1 );

    if ( o1 != o2 && o3 != o4 ) return true;

    if ( o1 == 0 && onSegment( p1, p2, q1 ) ) return true;
    if ( o2 == 0 && onSegment( p1, q2, q1 ) ) return true;
    if ( o3 == 0 && onSegment( p2, p1, q2 ) ) return true;
    if ( o4 == 0 && onSegment( p2, q1, q2 ) ) return true;

    return false;
}

int main( ) {
    Point p1 { 1, 1 }, p2 { 10, 1 }, q1 { 1, 2 }, q2 { 10, 2 };

    if ( intersect( p1, q1, p2, q2 ) ) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }

    p1 = { 10, 0 }, q1 = { 0, 10 }, p2 = { 0, 0 }, q2 = { 10, 10 };
    if ( intersect( p1, q1, p2, q2 ) ) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }

    return 0;
}