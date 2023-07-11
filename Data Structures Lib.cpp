#include <iostream>
#include "BinaryTree.h"
#include "Trie.h"
#include "Graph.h"
#include "LL.h"

int main() {
    // Testing Trie
    Trie trie;
    trie.insert("apple");
    trie.insert("banana");
    trie.insert("orange");

    std::cout << "Search 'apple': " << trie.search("apple") << std::endl;    // Output: 1 (true)
    std::cout << "Search 'grape': " << trie.search("grape") << std::endl;    // Output: 0 (false)

    std::cout << "Starts with 'app': " << trie.startsWith("app") << std::endl;  // Output: 1 (true)
    std::cout << "Starts with 'ban': " << trie.startsWith("ban") << std::endl;  // Output: 1 (true)
    std::cout << "Starts with 'gra': " << trie.startsWith("gra") << std::endl;  // Output: 0 (false)

    std::cout << "Trie Structure:" << std::endl;
    trie.printTrie(trie.root);

    std::cout << std::endl;

    // Testing BinaryTree
    Node* node1 = new Node(4);
    Node* node2 = new Node(2);
    Node* node3 = new Node(6);
    Node* node4 = new Node(1);
    Node* node5 = new Node(3);

    BinaryTree binaryTree(node1);
    binaryTree.addNode(node2);
    binaryTree.addNode(node3);
    binaryTree.addNode(node4);
    binaryTree.addNode(node5);

    std::cout << "Check value 3: " << binaryTree.checkVal(3) << std::endl;  // Output: 1 (true)
    std::cout << "Check value 5: " << binaryTree.checkVal(5) << std::endl;  // Output: 0 (false)

    std::cout << "Binary Tree Structure:" << std::endl;
    binaryTree.printTree(binaryTree.root);

    std::cout << std::endl;

    std::cout << "Depth-First Search (DFS) Traversal:" << std::endl;
    binaryTree.DFS();

    // Testing Graph
    std::unordered_map<int, std::vector<int>> neighbours;
    neighbours[1] = { 2, 3 };
    neighbours[2] = { 4 };
    neighbours[3] = { 5 };
    neighbours[4] = { 6, 7 };
    neighbours[5] = { 8 };
    neighbours[7] = { 9 };

    Graph graph(neighbours);

    std::cout << graph.traverse(1, 7) << std::endl;

    std::vector<int> visited;
    graph.newTraverse(1, 7, visited, "", 1);

    graph.addConnection(5, 10);
    graph.addConnection(10, 11);

    std::unordered_set<int> visitedSet;
    graph.dfs(1, visitedSet);

    //Testing Linked List
    LL linkedList(new LLNode(1));
    linkedList.addNode(new LLNode(2));
    linkedList.addNode(new LLNode(3));
    linkedList.addNode(new LLNode(4));

    // Print linked list before reversal
    std::cout << "Linked List before reversal: " << linkedList << std::endl;

    // Reverse the linked list
    linkedList.reverseLL(linkedList.head); // does not work!!!

    // Print linked list after reversal
    std::cout << "Linked List after reversal: " << linkedList << std::endl;

    return 0;
}