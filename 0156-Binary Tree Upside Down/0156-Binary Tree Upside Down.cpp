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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == nullptr || root->left == nullptr) {
            return root;
        }
        
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        TreeNode* prevRight = nullptr;
        while (curr) {
            TreeNode* next = curr->left;
            curr->left = prevRight;
            prevRight = curr->right;
            curr->right = prev;
            
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};
