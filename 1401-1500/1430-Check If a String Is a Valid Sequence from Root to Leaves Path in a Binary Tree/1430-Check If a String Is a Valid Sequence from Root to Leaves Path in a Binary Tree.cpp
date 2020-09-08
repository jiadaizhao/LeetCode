/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return dfs(root, arr, 0);
    }
    
private:
    bool dfs(TreeNode* root, vector<int>& arr, int start) {
        if (root == nullptr) {
            return false;
        }
        if (root->val != arr[start]) {
            return false;
        }
        if (start == arr.size() - 1) {
            return root->left == nullptr && root->right == nullptr;
        }
        return dfs(root->left, arr, start + 1) || dfs(root->right, arr, start + 1);
    }
};
