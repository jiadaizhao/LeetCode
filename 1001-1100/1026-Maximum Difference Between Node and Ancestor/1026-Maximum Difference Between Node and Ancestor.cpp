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
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
    
private:
    int dfs(TreeNode* root, int currMax, int currMin) {
        if (root == nullptr) {
            return currMax - currMin;
        }
        
        currMax = max(root->val, currMax);
        currMin = min(root->val, currMin);
        return max(dfs(root->left, currMax, currMin), dfs(root->right, currMax, currMin));
    }
};
