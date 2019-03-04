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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        
        TreeNode *node = root, *prev = nullptr;
        while (node) {
            prev = node;
            if (node->val < val) {
                node = node->right;
            }
            else if (node->val > val) {
                node = node->left;
            }
            else {
                return root;
            }
        }
        
        if (prev->val < val) {
            prev->right = new TreeNode(val);
        }
        else {
            prev->left = new TreeNode(val);
        }
        return root;
    }
};
