#ifndef LL_H
#define LL_H

#include <iostream>

class LLNode {
public:
    int val;
    LLNode* nextNode;

    LLNode(int val, LLNode* nextNode = nullptr);
};

class LL {

public:
    LLNode* head;

    LL(LLNode* head);

    void addNode(LLNode* node);
    void delNode(int nodeVal);
    void reverseLL(LLNode* node = nullptr, LLNode* prev = nullptr);
    friend std::ostream& operator<<(std::ostream& os, const LL& ll);
};

#endif // LL_H



