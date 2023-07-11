#include "Graph.h"
#include <iostream>
#include <algorithm>

Graph::Graph(const std::unordered_map<int, std::vector<int>>& neighbours) : neighbours(neighbours) {
    buildGraph();
}

void Graph::buildGraph() {
    for (const auto& neighbour : neighbours) {
        int key = neighbour.first;
        const std::vector<int>& values = neighbour.second;

        if (graph.find(key) != graph.end()) {
            graph[key].insert(graph[key].end(), values.begin(), values.end());
        }
        else {
            graph[key] = values;
        }
    }
}

std::string Graph::traverse(int start, int end, std::vector<int> visited, std::string s) {
    if (std::find(graph[start].begin(), graph[start].end(), end) != graph[start].end()) {
        s += (s == "") ? std::to_string(start) + " -> " + std::to_string(end) : " -> " + std::to_string(end);
        return "Found Link From (" + std::to_string(start) + " -> " + std::to_string(end) + "): " + s;
    }
    else {
        for (const auto& neighbour : neighbours) {
            int key = neighbour.first;
            const std::vector<int>& values = neighbour.second;

            if (std::find(visited.begin(), visited.end(), key) == visited.end() && graph.find(key) != graph.end()) {
                visited.push_back(start);
                std::string newPath = (s == "") ? std::to_string(start) + " -> " + std::to_string(key) : s + " -> " + std::to_string(key);
                std::string result = traverse(key, end, visited, newPath);
                if (result != "No Link Found From " + std::to_string(key) + " -> " + std::to_string(end)) {
                    return result;
                }
            }
        }
    }
    return "No Link Found From " + std::to_string(start) + " -> " + std::to_string(end);
}

void Graph::newTraverse(int start, int end, std::vector<int>& visited, std::string s, int curr) {
    if (visited.empty()) {
        visited.push_back(start);
        curr = start;
    }

    if (std::find(graph[start].begin(), graph[start].end(), end) != graph[start].end()) {
        if (!s.empty()) {
            std::cout << "Link from " << curr << " -> " << end << " Found: " << s << " -> " << end << std::endl;
        }
        else {
            std::cout << "Link from " << curr << " -> " << end << " Found: " << curr << " -> " << end << std::endl;
        }
    }
    else {
        for (const auto& i : graph[start]) {
            if (graph.find(i) != graph.end() && std::find(visited.begin(), visited.end(), i) == visited.end()) {
                visited.push_back(i);
                if (s.empty()) {
                    newTraverse(i, end, visited, std::to_string(start) + " -> " + std::to_string(i), curr);
                }
                else {
                    newTraverse(i, end, visited, s + " -> " + std::to_string(i), curr);
                }
            }
        }
    }
}

void Graph::addConnection(int a, int b) {
    if (graph.find(a) != graph.end()) {
        graph[a].push_back(b);
    }
    else {
        graph[a] = { b };
    }
}

void Graph::dfs(int node, std::unordered_set<int>& visited) {
    if (visited.find(node) == visited.end() && graph.find(node) != graph.end()) {
        std::cout << node << std::endl;
        visited.insert(node);

        for (const auto& neighbour : graph[node]) {
            dfs(neighbour, visited);
        }
    }
}