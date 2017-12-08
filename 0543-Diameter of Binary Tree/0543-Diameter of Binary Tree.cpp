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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int maxLen = 0;
        helper(root, maxLen);
        return maxLen - 1;
    }
    
private:
    int helper(TreeNode* root, int& maxLen) {
        if (root == nullptr) {
            return 0;
        }
        
        int left = helper(root->left, maxLen);
        int right = helper(root->right, maxLen);
        int len = left + 1 + right;
        maxLen = max(maxLen, len);
        return max(left, right) + 1;
    }
};
