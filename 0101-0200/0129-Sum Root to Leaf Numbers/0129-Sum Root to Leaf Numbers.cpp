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
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
    
private:
    void dfs(TreeNode* root, int curr, int& sum) {
        if (root == nullptr) {
            return;
        }
        
        curr = curr * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sum += curr;
        }
        else {
            dfs(root->left, curr, sum);
            dfs(root->right, curr, sum);
        }
    }
};
