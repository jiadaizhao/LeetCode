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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> St1, St2;
        pushLeft(St1, root1);
        pushLeft(St2, root2);
        vector<int> result;
        while (!St1.empty() || !St2.empty()) {
            stack<TreeNode*>& St = (St2.empty() || (!St1.empty() && St1.top()->val <= St2.top()->val)) ? St1 : St2;
            TreeNode* node = St.top();
            result.push_back(node->val);
            St.pop();
            pushLeft(St, node->right);
        }
        
        return result;
    }
    
private:
    void pushLeft(stack<TreeNode*>& St, TreeNode* node) {
        if (node) {
            St.push(node);
            pushLeft(St, node->left);
        }
    }
};
