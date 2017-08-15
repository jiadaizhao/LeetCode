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
        if (preorder.size() == 0)
        {
            return nullptr;
        }
        int preIndex = 0;
        return buildTree(preorder, preIndex, inorder, 0, inorder.size() - 1);
    }
    
private:
    TreeNode* buildTree(vector<int>& preorder, int& preIndex, vector<int>& inorder, int inStart, int inEnd)
    {
        if (inStart > inEnd)
        {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        int index = inStart;
        for (int i = inStart; i <= inEnd; ++i)
        {
            if (root->val == inorder[i])
            {
                index = i;
                break;
            }
        }
        
        root->left = buildTree(preorder, preIndex, inorder, inStart, index - 1);
        root->right = buildTree(preorder, preIndex, inorder, index + 1, inEnd);
        return root;
    }
};
