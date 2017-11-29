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
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int sum = 0;
        helper(root, 0, sum);
        return sum;
    }
    
private:
    void helper(TreeNode* root, int prev, int& sum) {
        prev = prev * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sum += prev;
            return;
        }
        
        if (root->left) {
            helper(root->left, prev, sum);
        }
        
        if (root->right) {
            helper(root->right, prev, sum);
        }
    }
};
