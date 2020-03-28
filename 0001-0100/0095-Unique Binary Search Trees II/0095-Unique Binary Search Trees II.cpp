/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct pairhash {
    size_t operator()(const pair<int, int> &p) const {
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0) {
            return {};
        }
        return dfs(1, n);
    }
    
private:
    unordered_map<pair<int, int>, vector<TreeNode*>, pairhash> table;
    vector<TreeNode*> dfs(int start, int end) {
        if (end < start) {
            return {nullptr};
        }
        
        if (table.find({start, end}) != table.end()) {
            return table[{start, end}];
        }
        
        vector<TreeNode*> result;
        
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> lefts = dfs(start, i - 1);
            vector<TreeNode*> rights = dfs(i + 1, end);
            for (TreeNode* left : lefts) {
                for (TreeNode* right : rights) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        
        table[{start, end}] = result;
        return result;
    }
};
