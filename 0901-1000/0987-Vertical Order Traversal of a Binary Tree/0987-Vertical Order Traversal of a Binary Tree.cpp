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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> result;
        for (auto p1 : table) {
            vector<int> col;
            for (auto p2 : p1.second) {
                for (int val : p2.second) {
                    col.push_back(val);
                }
            }
            result.push_back(col);
        }
        
        return result;
    }
    
private:
    map<int, map<int, set<int>>> table;
    void dfs(TreeNode* root, int x, int y) {
        if (root) {
            table[x][y].insert(root->val);
            dfs(root->left, x - 1, y + 1);
            dfs(root->right, x + 1, y + 1);
        }
    }
};
