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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> Q;
        Q.push(p);
        Q.push(q);
        while (!Q.empty()) {
            p = Q.front();
            Q.pop();
            q = Q.front();
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
            Q.push(q->left);
            Q.push(p->right);
            Q.push(q->right);
        }
        
        return true;
    }
};

// Recursive method
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        
        if (!p || !q) {
            return false;
        }
        
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
