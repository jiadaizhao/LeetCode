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
    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root, nullptr, nullptr);
    }
    
private:
    int dfs(TreeNode* root, TreeNode* p, TreeNode* gp) {
        if (root == nullptr) {
            return 0;
        }
        int result = (gp && (gp->val & 1) == 0) ? root->val : 0;
        int left = dfs(root->left, root, p);
        int right = dfs(root->right, root, p);
        return result + left + right;
    }
};
