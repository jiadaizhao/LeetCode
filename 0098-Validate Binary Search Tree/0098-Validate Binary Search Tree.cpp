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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)
        {
            return true;
        }
        
        stack<TreeNode*> St;
        TreeNode* node = root;
        TreeNode* prev = nullptr;
        while (!St.empty() || node)
        {
            if (node)
            {
                St.push(node);
                node = node->left;
            }
            else
            {
                node = St.top();
                if (prev && node->val <= prev->val)
                {
                    return false;
                }
                prev = node;
                St.pop();
                node = node->right;
            }
        }
        
        return true;
    }
};
