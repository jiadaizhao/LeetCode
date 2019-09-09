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
    int maxLevelSum(TreeNode* root) {
        int maxSum = root->val, maxLevel = 1, level = 0;
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            int qs = Q.size(), s = 0;
            for (int i = 0; i < qs; ++i) {
                TreeNode* node = Q.front();
                Q.pop();
                s += node->val;
                if (node->left) {
                    Q.push(node->left);
                }
                if (node->right) {
                    Q.push(node->right);
                }
            }
            ++level;
            if (s > maxSum) {
                maxSum = s;
                maxLevel = level;
            }
        }

        return maxLevel;
    }
};
