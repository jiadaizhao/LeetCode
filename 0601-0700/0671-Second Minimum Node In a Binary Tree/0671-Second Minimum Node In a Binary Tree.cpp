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
    int findSecondMinimumValue(TreeNode* root) {
        return helper(root, root->val);
    }
    
private:
    int helper(TreeNode* root, int smallest) {
        if (root == nullptr) {
            return -1;
        }
        
        int left = helper(root->left, smallest);
        int right = helper(root->right, smallest);
        if (left == -1) {
            if (right == -1) {
                return root->val > smallest ? root->val : -1;
            }
            else {
                return right;
            }
        }
        else if (right == -1) {
            return left;
        }
        else {
            return min(left, right);
        }
    }
};

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        return helper(root, root->val);
    }
    
private:
    int helper(TreeNode* root, int smallest) {
        if (root == nullptr) {
            return -1;
        }
        
        if (root->val != smallest) {
            return root->val;
        }
        
        int left = helper(root->left, smallest);
        int right = helper(root->right, smallest);
        if (left == -1) {
            return right;
        }
        else if (right == -1) {
            return left;
        }
        else {
            return min(left, right);
        }
    }
};
