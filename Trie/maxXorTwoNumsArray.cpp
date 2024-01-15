#include <bits/stdc++.h>

using namespace std;

/*
    LeetCode 421. Maximum XOR of Two Numbers in an Array
        Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 ≤ i ≤ j < n.

        We use a trie to store the binary representation of each number in the array.
        Then we traverse the array and for each number we find the maximum XOR of that
            number with any other number in the array.
        To find the maximum XOR of a number with any other number in the array, we traverse
            the trie and for each bit of the number we check if the opposite bit is present in the trie.
        If it is present, we set the corresponding bit in the answer to 1 and move to the next bit.
        If it is not present, we set the corresponding bit in the answer to 0 and move to the next bit.

        Time Complexity: O(n * 32), Space Complexity: O(n * 32)

        Note #1:
            We are not deleting the trie after each test case to free up memory.
            This is because if we delete the trie after each test case, the time complexity
            skyrockets and you will get a TLE for x = 2^32 - 1.

        Note #2:
            We can get a slightly better time complexity by only making the size of the trie
                as large as the maximum number in the array. But this only gives like a 100ms boost on LeetCode.
            This also prevents the use of bitset. But you can just do x & (1 << i) to get the ith bit of x,
                and x |= (1 << i) to set the ith bit of x.
            So in this case just find the largest number and use log2(largestNumber) + 1 as the size of depth of the trie.
            In this case the time complexity will be O(n * log2(maxNum)) instead of O(n * 32).
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
public:
    Trie() : root(new Node()) {}

    void insert(int x) {
        Node* node = root;
        bitset<32> bits(x);
        for ( int i = 31; i >= 0; i-- ) {
            node = node->add(bits[i]);
        }
    }

    int XOR(const int x) {
        Node* node = root;
        bitset<32> bits(x);
        bitset<32> ans(0);
        for ( int i = 31; i >= 0; i-- ) {
            if ( node->contains(!bits[i]) ) {
                ans.set(i);
                node = node->get(!bits[i]);
            }
            else {
                node = node->get(bits[i]);
            }
        }
        return static_cast<int>( ans.to_ulong() );
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mx = INT_MIN;
        Trie trie;
        for ( auto& c : nums ) {
            trie.insert(c);
        }

        return accumulate(nums.begin(), nums.end(), 0,
            [&trie](int x, int y) { return max(x, trie.XOR(y)); });
    }
};

int main() {
    vector<int> nums = { 3,10,5,25,2,8 };
    Solution s;
    cout << s.findMaximumXOR(nums) << endl;
    return 0;
}