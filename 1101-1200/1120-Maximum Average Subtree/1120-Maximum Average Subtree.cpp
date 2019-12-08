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
    double maximumAverageSubtree(TreeNode* root) {
        double maxAvg = 0;
        dfs(root, maxAvg);
        return maxAvg;
    }
    
private:
    pair<int, int> dfs(TreeNode* root, double& maxAvg) {
        if (root == nullptr) {
            return {0, 0};
        }
        auto [leftSum, leftCount] = dfs(root->left, maxAvg);
        auto [rightSum, rightCount] = dfs(root->right, maxAvg);
        int sum = leftSum + root->val + rightSum;
        int count = leftCount + 1 + rightCount;
        maxAvg = max(maxAvg, (double)sum / count);
        return {sum, count};
    }
};
