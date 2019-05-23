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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        int level = 0;
        while (!Q.empty()) {
            bool gap = false;
            int qs = Q.size();
            for (int i = 0; i < qs; ++i) {
                TreeNode* node = Q.front();
                Q.pop();
                if (node->left) {
                    if (gap) {
                        return false;
                    }
                    Q.push(node->left);
                    if (node->right) {
                        Q.push(node->right);
                    }
                    else {
                        gap = true;
                    }
                }
                else if (node->right) {
                    return false;
                }
                else {
                    gap = true;
                }
            }
            
            if (Q.size() && qs != (1 << level)) {
                return false;
            }
            ++level;
        }
        return true;
    }
};
