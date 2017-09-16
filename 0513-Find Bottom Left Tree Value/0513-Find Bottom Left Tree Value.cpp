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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        int result;
        while (!Q.empty())
        {
            int qs = Q.size();
            result = Q.front()->val;
            for (int i = 0; i < qs; ++i)
            {
                TreeNode* node = Q.front();
                Q.pop();
                if (node->left)
                {
                    Q.push(node->left);
                }
                
                if (node->right)
                {
                    Q.push(node->right);
                }
            }
        }
        
        return result;
    }
};
