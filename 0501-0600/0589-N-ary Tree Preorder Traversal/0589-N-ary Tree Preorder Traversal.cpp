/*
// Definition for a Node.
class Node {
public:
    int val;
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
    vector<int> preorder(Node* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        stack<Node*> St;
        St.push(root);
        while (!St.empty()) {
            Node* node = St.top();
            St.pop();
            result.push_back(node->val);
            int n = node->children.size();
            for (int i = n - 1; i >= 0; --i) {
                St.push(node->children[i]);
            }
        }
        return result;
    }
};
