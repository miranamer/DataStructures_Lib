#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

class Graph {
private:
    std::unordered_map<int, std::vector<int>> neighbours;
    std::unordered_map<int, std::vector<int>> graph;

    void buildGraph();

public:
    Graph(const std::unordered_map<int, std::vector<int>>& neighbours);
    std::string traverse(int start, int end, std::vector<int> visited = {}, std::string s = "");
    void newTraverse(int start, int end, std::vector<int>& visited, std::string s, int curr);
    void addConnection(int a, int b);
    void dfs(int node, std::unordered_set<int>& visited);
};

#endif // GRAPH_H

