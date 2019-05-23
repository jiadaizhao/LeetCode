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
    int distributeCoins(TreeNode* root) {
        int total = 0;
        dfs(root, total);
        return total;
    }

private:
    int dfs(TreeNode* root, int& total) {
        if (root == nullptr) {
            return 0;
        }

        int left = dfs(root->left, total);
        int right = dfs(root->right, total);
        total += abs(left) + abs(right);
        return root->val - 1 + left + right;
    }
};
