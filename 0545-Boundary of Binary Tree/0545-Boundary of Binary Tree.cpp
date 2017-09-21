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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> result;
        if (root == nullptr)
        {
            return result;
        }
        
        // Left boundary
        TreeNode* node = root;
        if (root->left == nullptr && root->right)
        {
            result.push_back(root->val);
        }
        else
        {
            while (node->left || node->right)
            {
                result.push_back(node->val);
                if (node->left)
                {
                    node = node->left;
                }
                else
                {
                    node = node->right;
                }
            }
        }        
        
        // Leaves
        stack<TreeNode*> St;        
        St.push(root);
        
        while (!St.empty())
        {
            node = St.top();
            St.pop();
            
            if (node->left == nullptr && node->right == nullptr)
            {
                result.push_back(node->val);
            }
            
            if (node->right)
            {
                St.push(node->right);
            }
            
            if (node->left)
            {
                St.push(node->left);
            }
        }
        
        // Right boundary
        node = root->right;
        while (node && (node->right || node->left))
        {
            St.push(node);
            if (node->right)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
        
        while (!St.empty())
        {
            result.push_back(St.top()->val);
            St.pop();
        }
        
        return result;
    }
};
