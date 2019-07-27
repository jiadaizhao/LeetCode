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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }

private:
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {nullptr, 0};
        }

        auto pl = dfs(root->left);
        auto pr = dfs(root->right);
        if (pl.second > pr.second) {
            return {pl.first, pl.second + 1};
        }
        else if (pl.second < pr.second) {
            return {pr.first, pr.second + 1};
        }
        else {
            return {root, pl.second + 1};
        }
    }
};
