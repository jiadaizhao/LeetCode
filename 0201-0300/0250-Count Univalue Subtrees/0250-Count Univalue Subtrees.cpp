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
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        isUnivalSubtree(root, count);
        return count;
    }
    
private:
    bool isUnivalSubtree(TreeNode* root, int& count) {
        if (root == nullptr) {
            return true;
        }
        
        bool left = isUnivalSubtree(root->left, count);
        bool right = isUnivalSubtree(root->right, count);
        if (left && right &&
           ((root->left == nullptr && root->right == nullptr) ||
            (root->left == nullptr && root->right && root->val == root->right->val ||
            (root->left && root->right == nullptr && root->val == root->left->val) ||
            (root->left && root->right && root->val == root->left->val && root->val == root->right->val)))) {
            ++count;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        int count = 0;
        isUnivalSubtree(root, count);
        return count;
    }
    
private:
    bool isUnivalSubtree(TreeNode* root, int& count) {
        if (root == nullptr) {
            return true;
        }
        
        bool left = isUnivalSubtree(root->left, count);
        bool right = isUnivalSubtree(root->right, count);
        if (left && right) {
            if (root->left && root->val != root->left->val) {
                return false;
            }
            
            if (root->right && root->val != root->right->val) {
                return false;
            }
            
            ++count;
            return true;
        }

        return false;
    }
};
