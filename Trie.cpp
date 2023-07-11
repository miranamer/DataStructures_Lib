#include "Trie.h"
#include <iostream>

TrieNode::TrieNode() {
    word = false;
}

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(const std::string& word) {
    TrieNode* curr = root;

    for (char c : word) {
        if (curr->children.find(c) == curr->children.end()) {
            curr->children[c] = new TrieNode();
        }
        curr = curr->children[c];
    }

    curr->word = true;
}

bool Trie::search(const std::string& word) {
    TrieNode* curr = root;

    for (char c : word) {
        if (curr->children.find(c) == curr->children.end()) {
            return false;
        }
        curr = curr->children[c];
    }

    return curr->word;
}

bool Trie::startsWith(const std::string& prefix) {
    TrieNode* curr = root;

    for (char c : prefix) {
        if (curr->children.find(c) == curr->children.end()) {
            return false;
        }
        curr = curr->children[c];
    }

    return true;
}

void Trie::printTrie(TrieNode* node, int gap) {
    for (auto& child : node->children) {
        std::cout << std::string(gap, ' ') << "|- " << child.first << std::endl;
        if (child.second->children.size() > 0) {
            printTrie(child.second, gap + 1);
        }
    }
}
