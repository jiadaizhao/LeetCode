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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1)
        {
            TreeNode* node = new TreeNode(v);
            node->left = root;
            return node;
        }
        
        helper(root, v, d);
        return root;
    }
    
private:
    void helper(TreeNode* root, int v, int d) {
        if (root == nullptr)
        {
            return;
        }
        if (d == 2)
        {
            TreeNode* nleft = new TreeNode(v);
            TreeNode* nright = new TreeNode(v);
            nleft->left = root->left;
            nright->right = root->right;
            root->left = nleft;
            root->right = nright;
        }
        else
        {
            helper(root->left, v, d - 1);
            helper(root->right, v, d - 1);
        }
    }
};
