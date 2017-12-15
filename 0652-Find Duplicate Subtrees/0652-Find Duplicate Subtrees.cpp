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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {        
        vector<TreeNode*> result;
        dfs(root, result);
        return result;
    }
    
private:
    unordered_map<string, int> table;
    string dfs(TreeNode* root, vector<TreeNode*>& result) {
        if (root == nullptr) {
            return "#";
        }
        
        string s = to_string(root->val) + "," + dfs(root->left, result) + "," + dfs(root->right, result);
        if (table[s]++ == 1) {
            result.push_back(root);
        }
        return s;
    }
};
