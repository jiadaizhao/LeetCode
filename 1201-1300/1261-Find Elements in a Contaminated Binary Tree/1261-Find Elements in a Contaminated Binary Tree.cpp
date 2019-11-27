/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    FindElements(TreeNode* root) {
        dfs(root, 0);
    }
    
    bool find(int target) {
        return table.count(target);
    }
    
private:
    unordered_set<int> table;
    void dfs(TreeNode* root, int curr) {
        if (root == nullptr) {
            return;
        }
        
        root->val = curr;
        table.insert(curr);
        dfs(root->left, curr * 2 + 1);
        dfs(root->right, curr * 2 + 2);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
