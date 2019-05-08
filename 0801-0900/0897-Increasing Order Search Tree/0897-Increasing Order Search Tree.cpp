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
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> St;
        TreeNode *node = root, *prev = nullptr, *res = nullptr;
        while (node || !St.empty()) {
            if (node) {
                St.push(node);
                node = node->left;
            }
            else {
                node = St.top();
                St.pop();
                node->left = nullptr;
                if (prev) {
                    prev->right = node;
                }
                else {
                    res = node;
                }
                prev = node;
                node = node->right;
            }
        }
        return res;
    }
};
