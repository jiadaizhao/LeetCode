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
    vector<int> findMode(TreeNode* root) {
        maxCount = modeCount = currVal = currCount = 0;
        vector<int> result;
        inorder(root, result);
        result.resize(modeCount);
        modeCount = 0;
        currCount = 0;
        inorder(root, result);
        return result;
    }
    
private:
    int maxCount;
    int modeCount;
    int currVal;
    int currCount;
    void inorder(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        
        inorder(root->left, result);
        handleVal(root->val, result);
        inorder(root->right, result);
    }
    
    void handleVal(int val, vector<int>& result) {
        if (val != currVal) {
            currVal = val;
            currCount = 0;
        }
        
        ++currCount;
        if (currCount > maxCount) {
            maxCount = currCount;
            modeCount = 1;
        }
        else if (currCount == maxCount) {
            ++modeCount;
            if (result.size()) {
                result[modeCount - 1] = val;
            }
        }        
    }
};
