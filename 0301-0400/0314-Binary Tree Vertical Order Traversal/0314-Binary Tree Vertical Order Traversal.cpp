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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        int minCol = 0, maxCol = 0;
        unordered_map<int, vector<int>> table;
        queue<pair<TreeNode*, int>> Q;
        Q.emplace(root, 0);
        while (!Q.empty()) {
            TreeNode* node = Q.front().first;
            int col = Q.front().second;
            Q.pop();
            minCol = min(minCol, col);
            maxCol = max(maxCol, col);
            table[col].push_back(node->val);
            if (node->left) {
                Q.emplace(node->left, col - 1);
            }
            if (node->right) {
                Q.emplace(node->right, col + 1);
            }
        }
        
        for (int i = minCol; i <= maxCol; ++i) {
            result.push_back(table[i]);
        }
        return result;
    }
};
