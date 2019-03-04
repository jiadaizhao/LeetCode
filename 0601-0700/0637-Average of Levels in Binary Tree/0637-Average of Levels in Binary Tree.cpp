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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        vector<double> result;
        while (!Q.empty()) {
            int qs = Q.size();
            double sum = 0;
            for (int i = 0; i < qs; ++i) {
                TreeNode* node = Q.front();
                Q.pop();
                sum += node->val;
                if (node->left) {
                    Q.push(node->left);
                }
                if (node->right) {
                    Q.push(node->right);
                }
            }
            result.push_back(sum / qs);
        }
        
        return result;
    }
};
