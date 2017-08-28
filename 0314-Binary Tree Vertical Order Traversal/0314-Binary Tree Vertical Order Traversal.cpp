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
        if (root == nullptr)
        {
            return result;
        }
        
        queue<Cell> Q;
        map<int, vector<int>> table;
        Q.emplace(0, root);
        table[0].push_back(root->val);
        
        while (!Q.empty())
        {
            int col = Q.front().col;
            TreeNode* node = Q.front().node;
            Q.pop();
            if (node->left)
            {
                Q.emplace(col - 1, node->left);
                table[col - 1].push_back(node->left->val);
            }
            
            if (node->right)
            {
                Q.emplace(col + 1, node->right);
                table[col + 1].push_back(node->right->val);
            }
        }
        
        for (auto it = table.begin(); it != table.end(); ++it)
        {
            result.push_back(it->second);
        }
        
        return result;
    }
    
private:
    struct Cell {
        int col;
        TreeNode* node;
        Cell(int c, TreeNode* p): col(c), node(p) {};
    };
};
