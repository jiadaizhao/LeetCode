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
    vector<vector<string>> printTree(TreeNode* root) {
        int row = height(root);
        int col = (1 << row) - 1;
        vector<vector<string>> result(row, vector<string>(col));
        fill(result, root, 0, 0, col - 1);        
        return result;
    }
    
private:
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        return 1 + max(height(root->left), height(root->right));
    }
    
    void fill(vector<vector<string>>& result, TreeNode* root, int level, int l, int r) {
        if (root == nullptr) {
            return;
        }
        
        result[level][(l + r) / 2] = to_string(root->val);
        fill(result, root->left, level + 1, l, (l + r) / 2 - 1);
        fill(result, root->right, level + 1, (l + r) / 2 + 1, r);
    }
};
