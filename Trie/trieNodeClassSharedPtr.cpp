#include <bits/stdc++.h>

using namespace std;

class Node {
    vector<shared_ptr<Node>> chars;

public:
    int endsAtCount = 0;
    int prefixCount = 0;

    Node() : chars(26) {}

    bool contains(char ch) const {
        return chars[ch - 'a'] != nullptr;
    }

    shared_ptr<Node>& get(char ch) {
        return chars[ch - 'a'];
    }

    shared_ptr<Node>& add(char ch) {
        if ( !contains(ch) ) {
            chars[ch - 'a'] = make_shared<Node>();
        }
        return chars[ch - 'a'];
    }

};

class Trie {
    shared_ptr<Node> root;

    inline shared_ptr<Node> prefixNode(const string& word) const {
        shared_ptr<Node> node = root;
        for ( auto& c : word ) {
            if ( node->prefixCount == 0 || !node->contains(c) ) return nullptr;
            node = node->get(c);
        }
        return node;
    }

public:
    Trie() : root(make_shared<Node>()) {}

    void insert(const string& word) {
        shared_ptr<Node> node = root;
        for ( auto& c : word ) {
            node->prefixCount++;
            node = node->add(c);
        }
        node->prefixCount++;
        node->endsAtCount++;
    }

    bool search(const string& word) {
        shared_ptr<Node> node = prefixNode(word);
        return node != nullptr && node->endsAtCount;
    }

    int countWordsEqualTo(const string& word) {
        shared_ptr<Node> node = prefixNode(word);
        return node != nullptr ? node->endsAtCount : 0;
    }

    bool startsWith(const string& prefix) {
        shared_ptr<Node> node = prefixNode(prefix);
        return node != nullptr;
    }

    int countWordsStartingWith(const string& prefix) {
        shared_ptr<Node> node = prefixNode(prefix);
        return node != nullptr ? node->prefixCount : 0;
    }

    void erase(const string& word) {
        stack<shared_ptr<Node>> stk;
        shared_ptr<Node> node = root;
        for ( auto& c : word ) {
            if ( !node->contains(c) ) return;
            stk.push(node);
            node = node->get(c);
        }
        if ( node->endsAtCount == 0 ) return;

        node->endsAtCount--;
        node->prefixCount--;

        while ( !stk.empty() ) {
            node = stk.top();
            stk.pop();
            node->prefixCount--;
        }
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;   // returns true
    cout << trie.search("app") << endl;     // returns false
    cout << trie.startsWith("app") << endl; // returns true
    trie.insert("app");
    cout << trie.search("app") << endl;     // returns true
    return 0;
}

