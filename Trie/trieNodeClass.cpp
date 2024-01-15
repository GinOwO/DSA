#include <bits/stdc++.h>

using namespace std;

class Node {
    Node* chars[26];
public:
    int endsAtCount = 0;
    int prefixCount = 0;

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
            if ( node->prefixCount == 0 || !node->contains(c) ) return nullptr;
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
            node->prefixCount++;
            node = node->add(c);
        }
        node->prefixCount++;
        node->endsAtCount++;
    }

    bool search(const string& word) {
        Node* node = prefixNode(word);
        return node != nullptr && node->endsAtCount;
    }

    int countWordsEqualTo(const string& word) {
        Node* node = prefixNode(word);
        return node != nullptr ? node->endsAtCount : 0;
    }

    bool startsWith(const string& prefix) {
        Node* node = prefixNode(prefix);
        return node != nullptr;
    }

    int countWordsStartingWith(const string& prefix) {
        Node* node = prefixNode(prefix);
        return node != nullptr ? node->prefixCount : 0;
    }

    void erase(const string& word) {
        stack<Node*> stk;
        Node* node = root;
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
/*
    insert samsung
insert samsung
insert vivo
countWordsEqualTo samsung
countWordsStartingWith vi
*/
    trie.insert("samsung");
    trie.insert("samsung");
    trie.insert("vivo");
    cout << trie.countWordsEqualTo("samsung") << endl;
    cout << trie.countWordsStartingWith("vi") << endl;

    return 0;
}