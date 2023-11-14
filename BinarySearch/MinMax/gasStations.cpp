// https://www.codingninjas.com/studio/problems/minimise-max-distance_7541449

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

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

double minimiseMaxDistance(const vector<int> &arr, int k){

}



int main(){
    cout << minimiseMaxDistance({1,2,3,4,5,6,7}, 6) << '\n';
}