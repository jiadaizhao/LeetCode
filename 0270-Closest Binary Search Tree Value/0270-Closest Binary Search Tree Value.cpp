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
    int closestValue(TreeNode* root, double target) {
        int result = root->val;
        while (root) {
            if (root->val == target) {
                return target;
            }
            else if (root->val < target) {
                if (target - root->val < abs(result - target)) {
                    result = root->val;
                }
                root = root->right;
            }
            else {
                if (root->val - target < abs(result - target)) {
                    result = root->val;
                }
                root = root->left;
            }
        }
        
        return result;
    }
};
