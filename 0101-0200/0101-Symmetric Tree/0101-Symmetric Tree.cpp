/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // Iterative method
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        queue<TreeNode*> Q;
        Q.push(root->left);
        Q.push(root->right);
        
        while (!Q.empty()) {
            TreeNode* p = Q.front();
            Q.pop();
            TreeNode* q = Q.front();
            Q.pop();
            
            if (!p && !q) {
                continue;
            }
            
            if (!p || !q) {
                return false;
            }
            
            if (p->val != q->val) {
                return false;
            }
            
            Q.push(p->left);
            Q.push(q->right);
            Q.push(p->right);
            Q.push(q->left);
        }
        
        return true;
    }
};

// Recursive method
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isSymmetric(root->left, root->right);
    }
    
private:
    bool isSymmetric(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        
        if (!p || !q) {
            return false;
        }
        
        return p->val == q->val && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
    }
};
