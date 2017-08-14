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
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0)
        {
            return vector<TreeNode*>();
        }
        return helper(1, n);
    }
    
private:
    map<pair<int, int>, vector<TreeNode*>> table;
    vector<TreeNode*> helper(int start, int end)
    {
        if (end < start)
        {
            return vector<TreeNode*>(1, nullptr);
        }
        
        if (table.find({start, end}) != table.end())
        {
            return table[{start, end}];
        }
        
        vector<TreeNode*> result;
        if (start == end)
        {
            result.push_back(new TreeNode(start));
            table[{start, end}] = result;
            return result;
        }
        
        for (int i = start; i <= end; ++i)
        {
            vector<TreeNode*> lefts = helper(start, i - 1);
            vector<TreeNode*> rights = helper(i + 1, end);
            for (TreeNode* left : lefts)
            {
                for (TreeNode* right : rights)
                {
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
