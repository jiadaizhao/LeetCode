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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> td(to_delete.begin(), to_delete.end());
        vector<TreeNode*> result;
        dfs(root, true, td, result);
        return result;
    }

private:
    TreeNode* dfs(TreeNode* root, bool prevDel, unordered_set<int>& td, vector<TreeNode*>& result) {
        if (root == nullptr) {
            return nullptr;
        }

        if (td.count(root->val)) {
            dfs(root->left, true, td, result);
            dfs(root->right, true, td, result);
            return nullptr;
        }
        else {
            if (prevDel == true) {
                result.push_back(root);
            }
            root->left = dfs(root->left, false, td, result);
            root->right = dfs(root->right, false, td, result);
            return root;
        }
    }
};
