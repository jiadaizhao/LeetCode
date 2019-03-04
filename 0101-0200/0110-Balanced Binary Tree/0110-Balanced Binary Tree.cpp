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
    bool isBalanced(TreeNode* root) {
        int h = 0;
        return helper(root, h);
    }
    
private:
    bool helper(TreeNode* root, int& h) {
        if (root == nullptr) {
            return true;
        }
        
        int lh = 0, rh = 0;
        bool isLeftBalanced = helper(root->left, lh);
        bool isRightBalanced = helper(root->right, rh);
        h = max(lh, rh) + 1;
        return isLeftBalanced && isRightBalanced && abs(lh - rh) <= 1;
    }
};
