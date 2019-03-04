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
    int largestBSTSubtree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int maxCount = 1;
        isBST(root, maxCount);
        return maxCount;
    }
    
private:
    struct resultType {
        bool isbst;
        int count;
        int minVal;
        int maxVal;
        resultType(bool ib, int c, int minv, int maxv): isbst(ib), count(c), minVal(minv), maxVal(maxv){}
    };

    resultType isBST(TreeNode* root, int& maxCount) {
        if (root == nullptr) {
            return resultType(true, 0, INT_MAX, INT_MIN);
        }
        
        resultType leftResult = isBST(root->left, maxCount);
        resultType rightResult = isBST(root->right, maxCount);
        if (leftResult.isbst && rightResult.isbst &&
            (root->val > leftResult.maxVal || root->left == nullptr) &&
            (root->val < rightResult.minVal || root->right == nullptr)) {
            maxCount = max(maxCount, 1 + leftResult.count + rightResult.count);
            return resultType(true, 1 + leftResult.count + rightResult.count, root->left ? leftResult.minVal : root->val, 
                    root->right ? rightResult.maxVal : root->val);
        }
        else {
            return resultType(false, 0, INT_MAX, INT_MIN); 
        }
    }
};
