#include "BinaryTree.h"
#include <iostream>

Node::Node(int value, Node* leftNode, Node* rightNode) {
    val = value;
    left = leftNode;
    right = rightNode;
}

BinaryTree::BinaryTree(Node* rootNode) {
    root = rootNode;
}

void BinaryTree::addNode(Node* node, bool startAtRoot) {
    Node* curr = startAtRoot ? root : this->root;

    while (true) {
        if (node->val >= curr->val) {
            if (curr->right == nullptr) {
                curr->right = node;
                break;
            }
            else {
                curr = curr->right;
            }
        }
        else {
            if (curr->left == nullptr) {
                curr->left = node;
                break;
            }
            else {
                curr = curr->left;
            }
        }
    }
}

bool BinaryTree::checkVal(int val, bool startAtRoot) {
    Node* curr = startAtRoot ? root : this->root;

    while (curr != nullptr) {
        if (curr->val == val) {
            return true;
        }
        else if (val > curr->val) {
            curr = curr->right;
        }
        else {
            curr = curr->left;
        }
    }

    return false;
}

void BinaryTree::DFS(Node* node) {
    Node* curr = node == nullptr ? root : node;

    std::cout << curr->val << std::endl;

    if (curr->left != nullptr && curr->right != nullptr) {
        DFS(curr->left);
        DFS(curr->right);
    }
    else {
        if (curr->left != nullptr) {
            DFS(curr->left);
        }
        if (curr->right != nullptr) {
            DFS(curr->right);
        }
    }
}

void BinaryTree::printTree(Node* node, int gap, bool left, bool right) {
    bool l = false, r = false;
    std::string direction = left ? "Left" : "Right";
    if (gap == 0) {
        std::cout << std::string(gap, ' ') << "|_" << node->val << " (Root) => Level: " << gap << std::endl;
    }
    else {
        std::cout << std::string(gap, ' ') << "|_" << node->val << " (" << direction << ") => Level: " << gap << std::endl;
    }

    if (node->right != nullptr) {
        printTree(node->right, gap + 1, false, true);
    }
    if (node->left != nullptr) {
        printTree(node->left, gap + 1, true, false);
    }
}
