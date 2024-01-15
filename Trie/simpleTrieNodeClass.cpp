#include <bits/stdc++.h>

using namespace std;

class Node {
    Node* chars[26];
public:
    bool endsAt = false;

    ~Node() {
        for ( auto& c : chars ) {
            if ( c != nullptr ) delete c;
        }
    }

    bool contains(char ch) const {
        return chars[ch - 'a'] != nullptr;
    }

    Node* get(char ch) {
        return chars[ch - 'a'];
    }

    Node* add(char ch) {
        if ( !contains(ch) ) {
            chars[ch - 'a'] = new Node();
        }
        return chars[ch - 'a'];
    }
};

class Trie {
    Node* root;

    inline Node* prefixNode(const string& word) {
        Node* node = root;
        for ( auto& c : word ) {
            if ( !node->contains(c) ) return nullptr;
            node = node->get(c);
        }
        return node;
    }

public:
    Trie() : root(new Node()) {}

    ~Trie() {
        delete root;
    }

    void insert(const string& word) {
        Node* node = root;
        for ( auto& c : word ) {
            node = node->add(c);
        }
        node->endsAt = true;
    }

    bool search(const string& word) {
        Node* node = prefixNode(word);
        return node != nullptr && node->endsAt;
    }

    bool startsWith(const string& prefix) {
        return prefixNode(prefix) != nullptr;
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