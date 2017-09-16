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
    vector<int> largestValues(TreeNode* root) {
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
            int maxVal = Q.front()->val;
            for (int i = 0; i < qs; ++i)
            {
                TreeNode* node = Q.front();
                Q.pop();
                maxVal = max(maxVal, node->val);
                if (node->left)
                {
                    Q.push(node->left);
                }
                
                if (node->right)
                {
                    Q.push(node->right);
                }
            }
            
            result.push_back(maxVal);
        }
        
        return result;
    }
};
