#ifndef BINARYTREE_H
#define BINARYTREE_H

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int value, Node* leftNode = nullptr, Node* rightNode = nullptr);

};

class BinaryTree {
public:
    Node* root;

    BinaryTree(Node* rootNode);

    void addNode(Node* node, bool startAtRoot = true);

    bool checkVal(int val, bool startAtRoot = true);

    void DFS(Node* node = nullptr);

    void printTree(Node* node, int gap = 0, bool left = false, bool right = false);

};

#endif  // BINARYTREE_H
