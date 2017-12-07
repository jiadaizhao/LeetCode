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
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> St;
        TreeNode* node = root;
        int minDiff = INT_MAX;
        TreeNode* prev = nullptr;
        while (node || !St.empty()) {
            if (node) {
                St.push(node);
                node = node->left;
            }
            else {
                node = St.top();
                if (prev) {
                    minDiff = min(minDiff, node->val - prev->val);
                }
                prev = node;
                St.pop();
                node = node->right;
            }
        }
        
        return minDiff;
    }
};
