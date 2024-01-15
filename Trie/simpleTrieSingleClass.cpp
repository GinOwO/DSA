#include <bits/stdc++.h>

using namespace std;

class Trie {
    vector<Trie*> children;
    bool endsAt = false;

    Trie* prefixNode(const string& word) {
        Trie* node = this;
        for ( auto& c : word ) {
            if ( node->children[c - 'a'] == nullptr ) return nullptr;
            node = node->children[c - 'a'];
        }
        return node;
    }

public:
    Trie() : children(26, nullptr) {}
    ~Trie() {
        for ( auto& node : children ) {
            if ( node != nullptr ) {
                delete node;
            }
        }
    }

    void insert(const string& word) {
        Trie* node = this;
        for ( auto& c : word ) {
            if ( node->children[c - 'a'] == nullptr ) {
                node->children[c - 'a'] = new Trie();
            }
            node = node->children[c - 'a'];
        }
        node->endsAt = true;
    }

    bool search(const string& word) {
        Trie* node = prefixNode(word);
        return node != nullptr && node->endsAt;
    }

    bool startsWith(const string& prefix) {
        Trie* node = prefixNode(prefix);
        return node != nullptr;
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