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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode dummy(-1);
        dummy.left = root;
        TreeNode* parent = &dummy;
        TreeNode* p = root;
        while (p)
        {
            if (p->val == key)
            {
                break;
            }
            
            parent = p;
            if (p->val < key)
            {
                p = p->right;
            }
            else
            {
                p = p->left;
            }
        }
        
        if (p == nullptr)
        {
            return dummy.left;
        }
        
        if (p->right == nullptr)
        {
            if (parent->left == p)
            {
                parent->left = p->left;
            }
            else
            {
                parent->right = p->left;
            }
            delete p;
        }
        else if (p->right->left == nullptr)
        {
            if (parent->left == p)
            {
                parent->left = p->right;
            }
            else
            {
                parent->right = p->right;
            }
            p->right->left = p->left;
            delete p;
        }
        else
        {
            parent = p->right;
            TreeNode* curr = parent->left;
            while (curr->left)
            {
                parent = curr;
                curr = curr->left;
            }
            p->val = curr->val;
            parent->left = curr->right;
            delete curr;
        }
        
        return dummy.left;
    }
};
