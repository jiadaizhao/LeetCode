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
    TreeNode* bstToGst(TreeNode* root) {
        stack<TreeNode*> St;
        TreeNode *node = root, *prev = nullptr;
        while (node || !St.empty()) {
            if (node) {
                St.push(node);
                node = node->right;
            }
            else {
                node = St.top();
                St.pop();
                if (prev) {
                    node->val += prev->val;
                }
                prev = node;
                node = node->left;
            }
        }
        return root;
    }
};
