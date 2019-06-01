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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> St;
        St.push(root);
        for (int i = 1; i < preorder.size(); ++i) {
            TreeNode* node = new TreeNode(preorder[i]);
            TreeNode* prev = nullptr;
            while (St.size() && node->val > St.top()->val) {
                prev = St.top();
                St.pop();
            }
            if (prev) {
                prev->right = node;
            }
            if (St.size() && St.top()->left == nullptr) {
                St.top()->left = node;
            }
            St.push(node);
        }
        return root;
    }
};


class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return dfs(preorder, i, INT_MAX);
    }
    
private:
    TreeNode* dfs(vector<int>& preorder, int& i, int limit) {
        if (i == preorder.size() || preorder[i] > limit) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = dfs(preorder, i, root->val);
        root->right = dfs(preorder, i, limit);
        return root;
    }
};
