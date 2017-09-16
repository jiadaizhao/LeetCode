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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        treeSum(root);

        vector<int> result;
        for (auto t : table)
        {
            if (t.second == maxCount)
            {
                result.push_back(t.first);
            }
        }
        
        return result;
    }
    
private:
    unordered_map<int, int> table;
    int maxCount;
    int treeSum(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        
        int left = treeSum(root->left);
        int right = treeSum(root->right);
        int sum = left + root->val + right;
        if (++table[sum] > maxCount)
        {
            maxCount = table[sum];
        }
        return sum;
    }
};
