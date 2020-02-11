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
    int maxProduct(TreeNode* root) {
        long maxP = 0, MOD = 1e9 + 7;
        long total = dfs(root, 0, maxP);
        dfs(root, total, maxP);
        return maxP % MOD;
    }
    
private:
    long dfs(TreeNode* root, long total, long& maxP) {
        if (root == nullptr) {
            return 0;
        }
        
        long sub = dfs(root->left, total, maxP) + root->val + dfs(root->right, total, maxP);
        maxP = max(maxP, sub * (total - sub));
        return sub;
    }
};
