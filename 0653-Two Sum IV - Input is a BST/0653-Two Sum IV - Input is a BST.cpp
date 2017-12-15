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
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) {
            return false;
        }
        
        stack<TreeNode*> St;
        St.push(root);
        while (!St.empty()) {
            TreeNode* node = St.top();
            if (table.find(k - node->val) != table.end()) {
                return true;
            }
            table.insert(node->val);
            St.pop();
            
            if (node->right) {
                St.push(node->right);
            }
            
            if (node->left) {
                St.push(node->left);
            }
        }
        return false;
    }
    
private:
    unordered_set<int> table;
};
