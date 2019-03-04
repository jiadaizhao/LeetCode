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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        helper(root, maxSum);
        return maxSum;
    }
private:
    int helper(TreeNode* root, int& maxSum) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftSum = max(helper(root->left, maxSum), 0);
        int rightSum = max(helper(root->right, maxSum), 0);
        
        maxSum = max(maxSum, leftSum + rightSum + root->val);
        return max(leftSum, rightSum) + root->val;
    }
};
