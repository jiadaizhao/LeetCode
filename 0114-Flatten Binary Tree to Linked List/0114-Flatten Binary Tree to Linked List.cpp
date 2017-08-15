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
    void flatten(TreeNode* root) {
        if (root == nullptr)
        {
            return;
        }
        
        stack<TreeNode*> St;
        St.push(root);
        while (!St.empty())
        {
            TreeNode* node = St.top();
            St.pop();
            
            if (node->right)
            {
                St.push(node->right);
            }
            
            if (node->left)
            {
                St.push(node->left);
            }
            
            node->left = nullptr;
            if (!St.empty())
            {
                node->right = St.top();
            }
        }
    }
};
