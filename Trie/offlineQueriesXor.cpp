#include <bits/stdc++.h>

using namespace std;

/*
    LeetCode: 1707. Maximum XOR With an Element From Array
        Given an array nums consisting of n numbers.
        Given a list of queries with q queries, where queries[i] = [xi, mi].
        For each query, compute the maximum XOR value of xi and any element of nums that does not exceed mi.
        Return an integer array answer where answer.length == q and answer[i] is the answer of the ith query.

        We use a Trie to store the numbers in nums.
        We sort the numbers in nums by their value.
        We create a vector order which stores the indices of the queries sorted by their mi value.
        We create a vector ans which stores the answer for each query and set its default values to -1.

        We iterate through the queries in the order specified by order, and for each query we insert all
            the numbers in nums that are less than or equal to the mi value of the query into the Trie.
        We then find the maximum XOR value of the xi value of the query and any number in the Trie that
            is less than or equal to the mi value of the query.
        We store the answer in ans[order[i]].
        Finally, we return ans.

        Time Complexity: O(nlogn + qlogq + n + q), Space Complexity: O(n + q)
*/

class Node {
    Node* children[2];
public:
    bool contains(bool x) {
        return children[x] != nullptr;
    }

    Node* add(bool x) {
        if ( !contains(x) ) {
            children[x] = new Node();
        }
        return children[x];
    }

    Node* get(bool x) {
        return children[x];
    }
};

class Trie {
    Node* root;
    int sz;
public:
    Trie(int n) : root(new Node()), sz(n) {}

    void insert(int x) {
        Node* node = root;
        for ( int i = sz; i >= 0; i-- ) {
            const bool bit = ( x >> i ) & 1;
            node = node->add(bit);
        }
    }

    int XOR(const int x) {
        Node* node = root;
        int ans = 0;
        for ( int i = sz; i >= 0; i-- ) {
            bool bit = x & ( 1 << i );
            if ( node->contains(!bit) ) {
                ans |= ( 1 << i );
                node = node->get(!bit);
            }
            else {
                node = node->get(bit);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size(), n = nums.size();
        vector<int> order(q), ans(q, -1);
        for ( int i = 0; i < q; i++ ) order[i] = i;

        sort(nums.begin(), nums.end());
        sort(order.begin(), order.end(), [&queries](const int x, const int y) {
            return queries[x][1] < queries[y][1];
            });

        Trie trie(29);

        for ( int i = 0, j = 0; i < q; i++ ) {
            vector<int>& cur = queries[order[i]];
            while ( j < n && nums[j] <= cur[1] ) {
                trie.insert(nums[j]);
                j++;
            }

            if ( j > 0 ) ans[order[i]] = trie.XOR(cur[0]);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 5,2,4,6,6,3 };
    vector<vector<int>> queries = { {12,4},{8,1},{6,3} };
    vector<int> ans = sol.maximizeXor(nums, queries);
    for ( int x : ans ) cout << x << ' ';
    return 0;
}