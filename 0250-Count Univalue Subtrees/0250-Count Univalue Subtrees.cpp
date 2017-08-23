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
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        isUnivalSubtree(root, count);
        return count;
    }
    
private:
    bool isUnivalSubtree(TreeNode* root, int& count)
    {
        if (root == nullptr)
        {
            return false;
        }
        
        if (root->left == nullptr && root->right == nullptr)
        {
            ++count;
            return true;
        }
        
        bool left = isUnivalSubtree(root->left, count);
        bool right = isUnivalSubtree(root->right, count);
        
        if ((root->left == nullptr && right && root->val == root->right->val) ||
            (root->right == nullptr && left && root->val == root->left->val) ||
            (left && right && root->val == root->left->val && root->val == root->right->val))
        {
            ++count;
            return true;
        }
        else
        {
            return false;
        }
    }
};
