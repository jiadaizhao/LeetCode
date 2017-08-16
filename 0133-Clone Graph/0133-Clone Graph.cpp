/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr)
        {
            return nullptr;
        }
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> table;
        table[node] = new UndirectedGraphNode(node->label);
        queue<UndirectedGraphNode*> Q;
        Q.push(node);
        while (!Q.empty())
        {
            UndirectedGraphNode* n = Q.front();
            Q.pop();
            for (UndirectedGraphNode* neighbor : n->neighbors)
            {
                if (table.find(neighbor) == table.end())
                {
                    table[neighbor] = new UndirectedGraphNode(neighbor->label);
                    Q.push(neighbor);
                }
                table[n]->neighbors.push_back(table[neighbor]);
            }
        }
        
        return table[node];
    }
};
