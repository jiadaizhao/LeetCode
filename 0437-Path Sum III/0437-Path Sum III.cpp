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
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr)
        {
            return 0;
        }
        
        int leftNum = pathSum(root->left, sum);
        int rightNum = pathSum(root->right, sum);
        
        int count = 0;
        dfs(root, sum, count);
        return leftNum + rightNum + count;
    }
private:
    void dfs(TreeNode* root, int sum, int& count)
    {
        if (root == nullptr)
        {
            return;
        }
        
        sum -= root->val;
        if (sum == 0)
        {
            ++count;
        }
        dfs(root->left, sum, count);
        dfs(root->right, sum, count);
    }
};
