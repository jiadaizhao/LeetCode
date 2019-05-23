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
    int minCameraCover(TreeNode* root) {
        int total = 0;
        return (dfs(root, total) == 0 ? 1 : 0) + total;
    }

private:
    int dfs(TreeNode* root, int& total) {
        if (root == nullptr) {
            return -1;
        }

        int left = dfs(root->left, total);
        int right = dfs(root->right, total);
        if (left == 0 || right == 0) {
            ++total;
            return 1;
        }
        if (left == 1 || right == 1) {
            return 2;
        }
        else {
            return 0;
        }
    }
};
