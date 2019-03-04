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
    vector<int> postorder(Node* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        if (root->children.size() == 0) {
            return {root->val};
        }
        
        stack<Node*> St;
        St.push(root);
        St.push(root->children[0]);
        Node* prev = root;
        while (!St.empty()) {
            Node* curr = St.top();

            Node* firstPrevChild = nullptr;
            for (Node* node : prev->children) {
                if (node == curr) {
                    firstPrevChild = node;
                    break;
                }
            }

            if (firstPrevChild) {
                if (curr->children.size()) {
                    St.push(curr->children[0]);
                }
            }
            else {
                int i;
                for (i = 0; i < curr->children.size(); ++i) {
                    if (curr->children[i] == prev) {
                        break;
                    }
                }
                if (i + 1 < curr->children.size()) {
                    St.push(curr->children[i + 1]);
                }
                else {
                    result.push_back(curr->val);
                    St.pop();
                }
            }
            
            prev = curr;
        }
        
        return result;
    }
};
