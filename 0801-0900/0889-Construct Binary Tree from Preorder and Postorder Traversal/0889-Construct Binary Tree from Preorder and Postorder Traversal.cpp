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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        vector<TreeNode*> St = {new TreeNode(pre[0])};
        int i = 0;
        for (int j = 1; j < pre.size(); ++j) {
            while (St.back()->val == post[i]) {
                St.pop_back();
                i += 1;
            }
            TreeNode* node = new TreeNode(pre[j]);
            if (St.back()->left) {
                St.back()->right = node;
            }
            else {
                St.back()->left = node;
            }
            St.push_back(node);
        }
        return St[0];
    }
};
