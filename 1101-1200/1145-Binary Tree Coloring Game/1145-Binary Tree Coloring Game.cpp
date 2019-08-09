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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        vector<int> count(2);
        dfs(root, x, count);
        return max({count[0], count[1], n - 1 - count[0] - count[1]}) > n / 2;
    }

private:
    int dfs(TreeNode* root, int x, vector<int>& count) {
        if (root == nullptr) {
            return 0;
        }

        int left = dfs(root->left, x, count);
        int right = dfs(root->right, x, count);
        if (root->val == x) {
            count[0] = left;
            count[1] = right;
        }
        return 1 + left + right;
    }
};
