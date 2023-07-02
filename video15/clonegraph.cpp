#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    unordered_map<Node*, Node*> visited;
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (visited.find(node) != visited.end()) return visited[node];
        
        auto new_node = new Node(node->val);
        visited[node] = new_node;
        for (auto neighbor : node->neighbors) {
            new_node->neighbors.push_back(cloneGraph(neighbor));
        }
        return new_node;
    }
};