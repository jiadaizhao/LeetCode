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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) {
            return nullptr;
        }
        for (int i = 0; i < inorder.size(); ++i) {
            table[inorder[i]] = i;
        }
        int postIndex = postorder.size() - 1;
        return dfs(inorder, 0, inorder.size() - 1, postorder, postIndex);
    }
    
private:
    unordered_map<int, int> table;
    TreeNode* dfs(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int& postIndex) {
        if (inStart > inEnd) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(postorder[postIndex--]);
        int index = table[root->val];
        
        root->right = dfs(inorder, index + 1, inEnd, postorder, postIndex);
        root->left = dfs(inorder, inStart, index - 1, postorder, postIndex);
        return root;
    }
};
