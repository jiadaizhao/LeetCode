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
    int longestConsecutive(TreeNode* root) {
        int maxLen = 0;
        helper(root, maxLen);
        return maxLen;
    }
private:
    int helper(TreeNode* root, int& maxLen) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftLen = helper(root->left, maxLen);
        int rightLen = helper(root->right, maxLen);
        int len = 1;
        if (root->left && root->val == root->left->val - 1) {
            len = 1 + leftLen;
        }
        
        if (root->right && root->val == root->right->val - 1) {
            len = max(len, 1 + rightLen);
        }
        
        if (len > maxLen) {
            maxLen = len;
        }
        
        return len;
    }
};
