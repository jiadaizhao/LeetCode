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
    int rob(TreeNode* root) {
        vector<int> result = robHelper(root);
        return max(result[0], result[1]);
    }
    
private:
    vector<int> robHelper(TreeNode* root) {
        vector<int> result(2);
        if (root == nullptr)
        {
            return result;
        }
        
        vector<int> left = robHelper(root->left);
        vector<int> right = robHelper(root->right);
        
        result[0] = root->val + left[1] + right[1];
        result[1] = max(left[0], left[1]) + max(right[0], right[1]);
        return result;
    }
};
