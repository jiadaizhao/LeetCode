// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        Node* curr = nullptr;
        if (node->right) {
            curr = node->right;
            while(curr->left) {
                curr = curr->left;
            }
        }
        else {
            curr = node->parent;
            while (curr && curr->val < node->val) {
                curr = curr->parent;
            }
        }
        
        return curr;
    }
};
