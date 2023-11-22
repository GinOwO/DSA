//https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

#include<bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

unsigned helper(vector<int>& arr, int d){
    unsigned total=0;
    for(auto&c:arr) total+= ceil(double(c)/double(d));
    return total;
}

int smallestDivisor(vector<int>& arr, int t){
    int l=1, r=*max_element(all(arr)), mid;
    while(l<=r){
        mid=l+r>>1;
        if(helper(arr, mid)<=t) r=mid-1;
        else l=mid+1;
    }
    return r+1;
}

int main(){
    vector<int> arr = {1,2,5,9};
    cout << smallestDivisor(arr, 6) << '\n';
}
