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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return dfs(root, 0, limit) ? nullptr : root;
    }

private:
    bool dfs(TreeNode* root, int curr,  int limit) {
        if (root == nullptr) {
            return true;
        }

        curr += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return curr < limit;
        }
        else {
            bool left = dfs(root->left, curr, limit);
            bool right = dfs(root->right, curr, limit);
            if (left) {
                root->left = nullptr;
            }
            if (right) {
                root->right = nullptr;
            }
            return left && right;
        }
    }
};
