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
    string tree2str(TreeNode* t) {
        string result;
        if (t == nullptr) {
            return "";
        }
        
        result += to_string(t->val);
        if (t->right) {
            result += '(' + tree2str(t->left) + ')';
            result += '(' + tree2str(t->right) + ')';
        }
        else if (t->left) {
            result += '(' + tree2str(t->left) + ')';
        }
        
        return result;
    }
};
