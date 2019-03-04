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
    bool checkEqualTree(TreeNode* root) {
        int sum = getSum(root);
        if (sum == 0) {
            return table[0] > 1;
        }
        return sum % 2 == 0 && table[sum / 2] > 0;
    }
    
private:
    unordered_map<int, int> table;
    int getSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int sum = root->val + getSum(root->left) + getSum(root->right);
        ++table[sum];
        return sum;
    }
};
