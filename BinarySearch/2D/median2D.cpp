// https://www.codingninjas.com/studio/problems/median-of-a-row-wise-sorted-matrix_1115473

#include <bits/stdc++.h>

using namespace std;

int ub(vector<int>& row, int x){
    int l=0, r=row.size()-1, mid;
    while(l<=r){
        mid=l+r>>1;
        if(x<row[mid]) r=mid-1;
        else l = mid+1;
    }
    return r+1;
}

int helper(vector<vector<int>>&matrix, int x){
    int t=0;
    for(auto&row:matrix) t+= ub(row,x);
    return t;
}

int median(vector<vector<int>>&matrix, int n, int m) {
    int l=INT_MAX, r=INT_MIN, req=n*m>>1, mid, q;
    for(auto&c:matrix){
        l = min(l, c[0]);
        r = max(r, c[m-1]);
    }

    while(l<=r){
        mid=l+r>>1;
        if(helper(matrix, mid)<=req) l=mid+1;
        else r=mid-1;
    }
    return l;
}