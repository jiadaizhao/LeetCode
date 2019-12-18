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
        int maxLen = 0;
        dfs(root, maxLen);
        return maxLen;
    }
    
private:
    int dfs(TreeNode* root, int& maxLen) {
        if (root == nullptr) {
            return 0;
        }
        
        int left = dfs(root->left, maxLen);
        int right = dfs(root->right, maxLen);
        maxLen = max(maxLen, left + right);
        return  1 + max(left, right);
    }
};
