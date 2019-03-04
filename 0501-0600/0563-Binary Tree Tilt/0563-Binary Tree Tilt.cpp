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
    int findTilt(TreeNode* root) {
        int sum = 0;
        findSum(root, sum);
        return sum;
    }
    
private:
    int findSum(TreeNode* root, int& sum) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftSum = findSum(root->left, sum);
        int rightSum = findSum(root->right, sum);
        sum += abs(leftSum - rightSum);
        return leftSum + root->val + rightSum;
    }
};
