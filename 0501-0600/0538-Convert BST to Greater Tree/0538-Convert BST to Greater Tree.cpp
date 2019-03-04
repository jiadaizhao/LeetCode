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
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> St;
        TreeNode* node = root;
        int presum = 0;
        while (node || !St.empty()) {
            if (node) {
                St.push(node);
                node = node->right;
            }
            else {
                node = St.top();
                St.pop();
                node->val += presum;
                presum = node->val;
                node = node->left;
            }
        }
        
        return root;
    }
};
