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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        
        queue<TreeNode*> Q;
        Q.push(root);
        bool fromLeft = true;
        while (!Q.empty()) {
            int qs = Q.size();
            vector<int> path(qs);
            for (int i = 0; i < qs; ++i) {
                TreeNode* node = Q.front();
                Q.pop();
                int index = fromLeft ? i : qs - 1 - i;
                path[index] = node->val;
                if (node->left) {
                    Q.push(node->left);
                }
                if (node->right) {
                    Q.push(node->right);
                }
            }
            
            fromLeft = !fromLeft;
            result.push_back(path);
        }
        
        return result;
    }
};
