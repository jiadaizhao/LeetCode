class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int n = equations.size();
        for (int i = 0; i < n; ++i)
        {
            string eq1 = equations[i].first;
            string eq2 = equations[i].second;
            Node *node1, *node2;
            if (table.find(equations[i].first) != table.end())
            {
                node1 = table[eq1];
            }
            else
            {
                node1 = new Node(values[i]);
                table[eq1] = node1;
            }
            
            if (table.find(equations[i].second) != table.end())
            {
                node2 = table[eq2];
            }
            else
            {
                node2 = new Node(1);
                table[eq2] = node2;
            }
            
            Node* parent1 = findParent(node1);
            Node* parent2 = findParent(node2);
            
            if (parent1 != parent2)
            {
                double ratio = node2->val * values[i] / node1->val;
                for (auto it = table.begin(); it != table.end(); ++it)
                {
                    if (findParent(it->second) == parent1)
                    {
                        it->second->val *= ratio;
                    }
                }
                parent2->parent = parent1;
            }
        }
        
        vector<double> result;
        for (auto& p : queries)
        {
            if (table.find(p.first) == table.end() || table.find(p.second) == table.end() || findParent(table[p.first]) != findParent(table[p.second]))
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(table[p.first]->val / table[p.second]->val);
            }
        }
        
        return result;
    }
    
private:
    struct Node {
        Node* parent;
        double val;
        Node(double v) : val(v) {parent = this;}
    };
    unordered_map<string, Node*> table;
    
    Node* findParent(Node* node)
    {
        if (node->parent == node)
        {
            return node;
        }
        
        return node->parent = findParent(node->parent);
    }
};
