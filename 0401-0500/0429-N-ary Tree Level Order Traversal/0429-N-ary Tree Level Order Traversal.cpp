/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        queue<Node*> Q;
        Q.push(root);
        while (!Q.empty()) {
            int qs = Q.size();
            vector<int> row;
            for (int i = 0; i < qs; ++i) {
                Node* node = Q.front();
                Q.pop();
                row.push_back(node->val);
                for (Node* child : node->children) {
                    Q.push(child);
                }
            }
            result.push_back(row);
        }
        return result;
    }
};
