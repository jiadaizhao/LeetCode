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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr)
        {
            return result;
        }
        stack<TreeNode*> St;
        TreeNode* node = root;
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
                result.push_back(node->val);
                St.pop();
                node = node->right;
            }
        }
        
        return result;
    }
};
