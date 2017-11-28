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
        int postIndex = postorder.size() - 1;
        return buildTree(inorder, 0, inorder.size() - 1, postorder, postIndex);
    }
    
private:
    TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int& postIndex) {
        if (inStart > inEnd) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(postorder[postIndex--]);
        int index = inStart;
        for (int i = inStart; i <= inEnd; ++i) {
            if (root->val == inorder[i]) {
                index = i;
                break;
            }
        }
        
        root->right = buildTree(inorder, index + 1, inEnd, postorder, postIndex);
        root->left = buildTree(inorder, inStart, index - 1, postorder, postIndex);
        return root;
    }
};
