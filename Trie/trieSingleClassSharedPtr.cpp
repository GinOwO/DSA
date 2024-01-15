#include <bits/stdc++.h>

using namespace std;

class Trie {
    vector<shared_ptr<Trie>> children;
    int endsAtCount = 0;
    int prefixCount = 0;

    shared_ptr<Trie> prefixNode(const string& word) {
        bool init = true;
        shared_ptr<Trie> node;
        for ( auto& c : word ) {
            if ( init ) {
                if ( this->prefixCount == 0 || this->children[c - 'a'] == nullptr ) {
                    return nullptr;
                }
                node = this->children[c - 'a'];
                init = false;
                continue;
            }
            if ( node->prefixCount == 0 || node->children[c - 'a'] == nullptr ) {
                return nullptr;
            }
            node = node->children[c - 'a'];
        }
        return node;
    }

public:
    Trie() : children(26) {}

    void insert(const string& word) {
        bool init = true;
        shared_ptr<Trie> node;
        for ( auto& c : word ) {
            if ( init ) {
                if ( this->children[c - 'a'] == nullptr ) {
                    this->children[c - 'a'] = make_shared<Trie>();
                }
                this->prefixCount++;
                node = this->children[c - 'a'];
                init = false;
                continue;
            }
            if ( node->children[c - 'a'] == nullptr ) {
                node->children[c - 'a'] = make_shared<Trie>();
            }
            node->prefixCount++;
            node = node->children[c - 'a'];
        }
        node->prefixCount++;
        node->endsAtCount++;
    }

    bool search(const string& word) {
        shared_ptr<Trie> node = prefixNode(word);
        return node->endsAtCount;
    }

    int countWordsEqualTo(const string& word) {
        shared_ptr<Trie> node = prefixNode(word);
        return node != nullptr ? node->endsAtCount : 0;
    }

    bool startsWith(const string& prefix) {
        shared_ptr<Trie> node = prefixNode(prefix);
        return node != nullptr;
    }

    int countWordsStartingWith(const string& prefix) {
        shared_ptr<Trie> node = prefixNode(prefix);
        return node != nullptr ? node->prefixCount : 0;
    }

    void erase(const string& word) {
        stack<shared_ptr<Trie>> stk;
        shared_ptr<Trie> node;
        bool init = true;
        for ( auto& c : word ) {
            if ( init ) {
                if ( this->children[c - 'a'] == nullptr ) return;
                node = this->children[c - 'a'];
                init = false;
                continue;
            }
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

        this->prefixCount--;
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