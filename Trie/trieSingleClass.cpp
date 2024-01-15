#include <bits/stdc++.h>

using namespace std;

class Trie {
    vector<Trie*> children;
    int endsAtCount = 0;
    int prefixCount = 0;

    Trie* prefixNode(const string& word) {
        Trie* node = this;
        for ( auto& c : word ) {
            if ( node->prefixCount == 0 || node->children[c - 'a'] == nullptr ) return nullptr;
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
            node->prefixCount++;
            node = node->children[c - 'a'];
        }
        node->prefixCount++;
        node->endsAtCount++;
    }

    bool search(const string& word) {
        Trie* node = prefixNode(word);
        return node->endsAtCount;
    }

    int countWordsEqualTo(const string& word) {
        Trie* node = prefixNode(word);
        return node != nullptr ? node->endsAtCount : 0;
    }

    bool startsWith(const string& prefix) {
        Trie* node = prefixNode(prefix);
        return node != nullptr;
    }

    int countWordsStartingWith(const string& prefix) {
        Trie* node = prefixNode(prefix);
        return node != nullptr ? node->prefixCount : 0;
    }

    void erase(const string& word) {
        stack<Trie*> stk;
        Trie* node = this;
        for ( auto& c : word ) {
            if ( node->children[c - 'a'] == nullptr ) return;
            stk.push(node);
            node = node->children[c - 'a'];
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
    trie.insert("qwer");
    trie.insert("asdf");
    trie.insert("zxcv");
    cout << trie.countWordsEqualTo("banana") << endl;
    trie.erase("qwer");
    cout << trie.countWordsStartingWith("app") << endl;

    return 0;
}