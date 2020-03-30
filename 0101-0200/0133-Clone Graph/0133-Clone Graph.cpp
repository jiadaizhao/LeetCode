/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        unordered_map<Node*, Node*> table;
        table[node] = new Node(node->val);
        queue<Node*> Q;
        Q.push(node);
        while (!Q.empty()) {
            Node* n = Q.front();
            Q.pop();
            for (Node* neighbor : n->neighbors) {
                if (!table.count(neighbor)) {
                    table[neighbor] = new Node(neighbor->val);
                    Q.push(neighbor);
                }
                table[n]->neighbors.push_back(table[neighbor]);
            }
        }
        
        return table[node];
    }
};
