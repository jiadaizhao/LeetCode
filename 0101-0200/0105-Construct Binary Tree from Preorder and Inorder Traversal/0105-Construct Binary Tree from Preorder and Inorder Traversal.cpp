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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return nullptr;
        }
        for (int i = 0; i < inorder.size(); ++i) {
            table[inorder[i]] = i;
        }
        int preIndex = 0;
        return dfs(preorder, preIndex, inorder, 0, inorder.size() - 1);
    }
    
private:
    unordered_map<int, int> table;
    TreeNode* dfs(vector<int>& preorder, int& preIndex, vector<int>& inorder, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        int index = table[root->val];
        
        root->left = dfs(preorder, preIndex, inorder, inStart, index - 1);
        root->right = dfs(preorder, preIndex, inorder, index + 1, inEnd);
        return root;
    }
};
