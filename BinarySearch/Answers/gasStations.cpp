// https://www.codingninjas.com/studio/problems/minimise-max-distance_7541449

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
#define tol 1e-7

/* //Heap soln
double minimiseMaxDistance(const vector<int> &arr, int k){
    priority_queue<pair<ld,ld>, vector<pair<ld,ld>>> pq;
    for(int i=1; i<arr.size(); i++) pq.push({arr[i]-arr[i-1], i-1});
    int tc[arr.size()-1] = {0};

    for(int i=1; i<=k; i++){
        auto p = pq.top(); pq.pop();
        int idx = p.second;
        tc[idx]++;
        ld diff = arr[idx+1]-arr[idx];
        ld len = diff/ld(tc[idx]+1);
        pq.push({len, idx});
    }

    return pq.top().first;
}
*/

int helper(const vector<int>& arr, ld d) {
    int cnt = 0;
    for ( int i = 1; i < arr.size(); i++ ) {
        int k = ( arr[i] - arr[i - 1] ) / d;
        if ( ( arr[i] - arr[i - 1] ) / d == k * d ) k--;
        cnt += k;
    }
    return cnt;
}

double minimiseMaxDistance(const vector<int>& arr, int k) {
    ld l = 0, r = INT_MIN, mid;
    for ( int i = 1; i < arr.size(); i++ ) r = max(r, ld(arr[i] - arr[i - 1]));

    while ( r - l > tol ) {
        mid = ( l + r ) / ( 2.0 );
        int cnt = helper(arr, mid);
        if ( cnt > k ) l = mid;
        else r = mid;
    }
    return r;
}

int main() {
    cout << minimiseMaxDistance({ 1,2,3,4,5,6,7 }, 6) << '\n';
}