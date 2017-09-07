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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        helper(root, nullptr, sum);
        return sum;
    }
    
private:
    void helper(TreeNode* root, TreeNode* parent, int& sum)
    {
        if (root == nullptr)
        {
            return;
        }
        
        if (root->left == nullptr && root->right == nullptr && parent && parent->left == root)
        {
            sum += root->val;
        }
        
        helper(root->left, root, sum);
        helper(root->right, root, sum);
    }
};
