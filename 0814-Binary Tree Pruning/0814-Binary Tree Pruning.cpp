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
    TreeNode* pruneTree(TreeNode* root) {
        return contain1(root) ? root : nullptr;
    }
    
private:
    bool contain1(TreeNode* root) {
        if (root == nullptr) {
            return false;
        }
        
        bool left = contain1(root->left);
        bool right = contain1(root->right);
        if (!left) {
            root->left = nullptr;
        }
        if (!right) {
            root->right = nullptr;
        }
        return left || right || root->val == 1;
    }
};
