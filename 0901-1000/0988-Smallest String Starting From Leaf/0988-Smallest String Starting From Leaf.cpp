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
    string smallestFromLeaf(TreeNode* root) {
        return dfs(root, "");
    }
    
private:
    string dfs(TreeNode* root, string prev) {
        if (root == nullptr) {
            return "{";
        }
        
        string curr = string(1, 'a' + root->val) + prev;
        if (root->left == nullptr && root->right == nullptr) {
            return curr;
        }
        else {
            return min(dfs(root->left, curr), dfs(root->right, curr));
        }
    }
};
