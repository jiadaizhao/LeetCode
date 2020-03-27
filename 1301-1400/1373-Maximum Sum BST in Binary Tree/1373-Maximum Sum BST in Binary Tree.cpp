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
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        dfs(root, maxSum);
        return maxSum;
    }
    
private:
    vector<int> dfs(TreeNode* root, int& maxSum) {
        if (root == nullptr) {
            return {0, true, INT_MAX, INT_MIN};
        }
        vector<int> left = dfs(root->left, maxSum);
        vector<int> right = dfs(root->right, maxSum);
        if (left[1] && root->val > left[3] && right[1] && root->val < right[2]) {
            int currSum = root->val + left[0] + right[0];
            maxSum = max(maxSum, currSum);
            return {currSum, true, left[2] != INT_MAX ? left[2] : root->val,
                    right[3] != INT_MIN ? right[3] : root->val};
        }
        else {
            return {0, false, INT_MIN, INT_MAX};
        }
    }
};
