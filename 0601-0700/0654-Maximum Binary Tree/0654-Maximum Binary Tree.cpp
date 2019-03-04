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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> St;
        for (int num : nums) {
            TreeNode* node = new TreeNode(num);
            while (St.size() && St.back()->val < num) {
                node->left = St.back();
                St.pop_back();
            }
            
            if (St.size()) {
                St.back()->right = node;
            }
            St.push_back(node);
        }
        
        return St[0];            
    }
};
