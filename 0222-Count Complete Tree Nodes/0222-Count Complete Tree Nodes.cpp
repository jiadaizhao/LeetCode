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
    int countNodes(TreeNode* root) {
        int h = height(root);
        int count = 0;
        while (root)
        {
            int rh = height(root->right);
            if (rh == h - 1)
            {
                count += (1 << h);
                root = root->right;
            }
            else
            {
                count += (1 << (h - 1));
                root = root->left;
            }
            --h;
        }
        
        return count;        
    }
    
private:
    int height(TreeNode* root)
    {
        int h = -1;
        while (root)
        {
            ++h;
            root = root->left;
        }
        return h;
    }
};
