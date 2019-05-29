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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (root == nullptr || root->val < val) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        else {
            root->right = insertIntoMaxTree(root->right, val);
            return root;
        }
    }
};


class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode *prev = nullptr, *curr = root;
        while (curr && curr->val > val) {
            prev = curr;
            curr = curr->right;
        }
        
        TreeNode* node = new TreeNode(val);
        node->left = curr;
        if (prev) {
            prev->right = node;
        }
        
        return prev ? root : node;
    }
};
