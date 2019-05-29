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
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, 1, nullptr, x, y);
        return depthTable[x] == depthTable[y] && parent[x] != parent[y];
    }
    
private:
    unordered_map<int, TreeNode*> parent;
    unordered_map<int, int> depthTable;
    void dfs(TreeNode* root, int depth, TreeNode* prev, int x, int y) {
        if (root == nullptr) {
            return;
        }
        
        if (root->val == x) {
            parent[x] = prev;
            depthTable[x] = depth;
            return;
        }
        else if (root->val == y) {
            parent[y] = prev;
            depthTable[y] = depth;
            return;
        }
        
        dfs(root->left, depth + 1, root, x, y);
        dfs(root->right, depth + 1, root, x, y);
    }
};
