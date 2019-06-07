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
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
    
private:
    int dfs(TreeNode* root, int curr) {
        if (root == nullptr) {
            return 0;
        }
        
        curr = curr * 2 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return curr;
        }
        else {
            return dfs(root->left, curr) + dfs(root->right, curr);
        }
    }
};
