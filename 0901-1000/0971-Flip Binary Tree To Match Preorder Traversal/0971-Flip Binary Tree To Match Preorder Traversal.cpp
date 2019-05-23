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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> result;
        int i = 0;
        return dfs(root, voyage, i, result) ? result : vector<int>{-1};
    }
    
private:
    bool dfs(TreeNode* root, vector<int>& voyage, int& i, vector<int>& result) {
        if (root == nullptr) {
            return true;
        }
        
        if (root->val != voyage[i++]) {
            return false;
        }
        
        if (root->left && root->left->val != voyage[i]) {
            result.push_back(root->val);
            return dfs(root->right, voyage, i, result) && dfs(root->left, voyage, i, result);
        }
        
        return dfs(root->left, voyage, i, result) && dfs(root->right, voyage, i, result);
    }
};
