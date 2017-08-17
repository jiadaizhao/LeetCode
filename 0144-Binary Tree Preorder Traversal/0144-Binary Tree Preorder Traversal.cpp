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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr)
        {
            return result;
        }
        stack<TreeNode*> St;
        St.push(root);
        while (!St.empty())
        {
            TreeNode* node = St.top();
            result.push_back(node->val);
            St.pop();
            
            if (node->right)
            {
                St.push(node->right);
            }
            
            if (node->left)
            {
                St.push(node->left);
            }
        }
        
        return result;
    }
};
