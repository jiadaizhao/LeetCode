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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr)
        {
            return result;
        }
        
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty())
        {
            int qs = Q.size();
            for (int i = 0; i < qs; ++i)
            {
                TreeNode* node = Q.front();
                Q.pop();
                if (i == 0)
                {
                    result.push_back(node->val);
                }
                
                if (node->right)
                {
                    Q.push(node->right);
                }
                if (node->left)
                {
                    Q.push(node->left);
                }
            }
        }
        
        return result;
    }
};
