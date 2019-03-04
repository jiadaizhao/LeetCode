/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        queue<TreeNode*> Q;
        Q.push(root);
        int depth = 0;
        while (!Q.empty()) {
            ++depth;
            int qs = Q.size();
            for (int i = 0; i < qs; ++i) {
                TreeNode* node = Q.front();
                Q.pop();
                if (node->left == nullptr && node->right == nullptr) {
                    return depth;
                }
                
                if (node->left) {
                    Q.push(node->left);
                }
                if (node->right) {
                    Q.push(node->right);
                }
            }
        }
        
        return depth;
    }
};

// DFS
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        if (root->left == nullptr) {
            return 1 + minDepth(root->right);
        }
        
        if (root->right == nullptr) {
            return 1 + minDepth(root->left);
        }
        
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
