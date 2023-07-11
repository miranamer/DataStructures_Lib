#include "LL.h"

LLNode::LLNode(int __val, LLNode* __nextNode) {
    val = __val;
    nextNode = __nextNode;
};

LL::LL(LLNode* __head) {
    head = __head;
};

void LL::addNode(LLNode* node) {
    if (head == nullptr) {
        head = node;
        return;
    }

    LLNode* curr = head;
    while (curr->nextNode != nullptr) {
        curr = curr->nextNode;
    }

    curr->nextNode = node;
}

void LL::delNode(int nodeVal) {
    LLNode* curr = head;

    if (curr->val == nodeVal) {
        if (curr->nextNode != nullptr) {
            head = curr->nextNode;
        }
        else {
            head = nullptr;
        }
        return;
    }

    while (curr->nextNode) {
        if (curr->nextNode->val == nodeVal) {
            curr->nextNode = curr->nextNode->nextNode;
            return;
        }

        curr = curr->nextNode;
    }
    return;
}

void LL::reverseLL(LLNode* node, LLNode* prev) {
    if (node == nullptr) {
        return;
    }

    LLNode* NextNode = node->nextNode;
    
    if (NextNode == nullptr) {
        this->head = node;
    }

    node->nextNode = prev;

    reverseLL(node = NextNode, prev = node);
}

std::ostream& operator<<(std::ostream& os, const LL& ll) {
    LLNode* curr = ll.head;

    if (curr == nullptr) {
        os << "Empty Linked List";
        return os;
    }

    os << curr->val;
    curr = curr->nextNode;

    while (curr != nullptr) {
        os << " -> " << curr->val;
        curr = curr->nextNode;
    }

    return os;
}



