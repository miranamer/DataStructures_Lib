#ifndef TRIE_H
#define TRIE_H

#include <unordered_map>
#include <string>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool word;

    TrieNode();

};

class Trie {
public:
    TrieNode* root;

    Trie();

    void insert(const std::string& word);

    bool search(const std::string& word);

    bool startsWith(const std::string& prefix);

    void printTrie(TrieNode* node, int gap = 1);

};

#endif  // TRIE_H
