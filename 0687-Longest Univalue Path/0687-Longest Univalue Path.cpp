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
    int longestUnivaluePath(TreeNode* root) {
        int maxLen = 0;
        longestPath(root, maxLen);
        return maxLen;
    }
    
private:
    int longestPath(TreeNode* root, int& maxLen) {
        if (root == nullptr) {
            return -1;
        }
        
        int leftLen = longestPath(root->left, maxLen);
        int rightLen = longestPath(root->right, maxLen);
        int len = 0;
        int currLen = 0;
        if (root->left && root->left->val == root->val) {
            len = leftLen + 1;
            currLen = len;
        }
        if (root->right && root->right->val == root->val) {
            len = max(len, rightLen + 1);
            currLen += rightLen + 1;
        }
        
        maxLen = max(maxLen, currLen);
        return len;
    }
};
