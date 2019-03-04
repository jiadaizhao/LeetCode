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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        height(root, result);
        return result;
    }
    
private:
    int height(TreeNode* root, vector<vector<int>>& result) {
        if (root == nullptr) {
            return -1;
        }
        
        int leftHeight = height(root->left, result);
        int rightHeight = height(root->right, result);
        int h = 1 + max(leftHeight, rightHeight);
        if (result.size() <= h) {
            result.push_back({});
        }
        result[h].push_back(root->val);
        return h;
    }
};
