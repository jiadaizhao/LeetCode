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
        int downLen = 0, upLen = 0, maxLen = 0;
        helper(root, downLen, upLen, maxLen);
        return maxLen;
    }
private:
    void helper(TreeNode* root, int& downLen, int& upLen, int& maxLen) {
        if (root == nullptr) {
            return;
        }
        
        int lDownLen = 0, lUpLen = 0;
        helper(root->left, lDownLen, lUpLen, maxLen);
        int rDownLen = 0, rUpLen = 0;
        helper(root->right, rDownLen, rUpLen, maxLen);
        
        if (root->left) {
            if (root->val == root->left->val - 1) {
                downLen = 1 + lDownLen;
            }
            else if (root->val == root->left->val + 1) {
                upLen = 1 + lUpLen;
            }
        }
        
        if (root->right) {
            if (root->val == root->right->val - 1) {
                downLen = max(downLen, 1 + rDownLen);
            }
            else if (root->val == root->right->val + 1) {
                upLen = max(upLen, 1 + rUpLen);
            }
        }
        
        int len = downLen + 1 + upLen;
        if (len > maxLen) {
            maxLen = len;
        }
    }
};
