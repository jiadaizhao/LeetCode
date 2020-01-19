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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        int sum = 0;
        while (!Q.empty()) {
            int qs = Q.size();
            sum = 0;
            while (qs--) {
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
        }
        
        return sum;
    }
};
