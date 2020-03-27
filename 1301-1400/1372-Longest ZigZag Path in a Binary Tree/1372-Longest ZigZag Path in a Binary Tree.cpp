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
    int longestZigZag(TreeNode* root) {
        int maxLen = 0, leftLen = -1, rightLen = -1;
        dfs(root, leftLen, rightLen, maxLen);
        return maxLen;
    }
    
private:
    void dfs(TreeNode* root, int& leftLen, int& rightLen, int& maxLen) {
        if (root == nullptr) {
            return;
        }
        int leftLen1 = -1, rightLen1 = -1, leftLen2 = -1, rightLen2 = -1;
        dfs(root->left, leftLen1, rightLen1, maxLen);
        dfs(root->right, leftLen2, rightLen2, maxLen);
        maxLen = max(maxLen, 1 + max(rightLen1, leftLen2));
        leftLen = 1 + rightLen1;
        rightLen = 1 + leftLen2;
    }
};
