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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, sum, path, result);
        return result;
    }
    
private:
    void dfs(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& result) {
        if (root == nullptr) {
            return;
        }
        
        sum -= root->val;
        path.push_back(root->val);
        if (sum == 0 && root->left == nullptr && root->right == nullptr) {
            result.push_back(path);
        }
        else {
            dfs(root->left, sum, path, result);
            dfs(root->right, sum, path, result);
        }        
        path.pop_back();
    }
};
