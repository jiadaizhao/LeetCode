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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        return construct(arr, 0, arr.size() - 1);
    }
    
private:
    void inorder(TreeNode* root, vector<int>& arr) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    
    TreeNode* construct(vector<int>& arr, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = construct(arr, start, mid - 1);
        root->right = construct(arr, mid + 1, end);
        return root;
    }
};
