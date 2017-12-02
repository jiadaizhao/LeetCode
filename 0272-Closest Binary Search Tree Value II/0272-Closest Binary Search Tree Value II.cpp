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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<TreeNode*> pre;
        stack<TreeNode*> suc;
        while (root) {
            if (root->val <= target) {
                pre.push(root);
                root = root->right;
            }
            else {
                suc.push(root);
                root = root->left;
            }
        }
        
        vector<int> result;
        while (k--) {
            if (pre.empty()) {
                result.push_back(getNextSuccessor(suc));
            }
            else if (suc.empty()) {
                result.push_back(getNextPredecessor(pre));
            }
            else {
                if (abs(pre.top()->val - target) < abs(suc.top()->val - target)) {
                    result.push_back(getNextPredecessor(pre));
                }
                else {
                    result.push_back(getNextSuccessor(suc));
                }
            }
        }
        
        return result;
    }
    
private:
    int getNextPredecessor(stack<TreeNode*>& pre) {
        TreeNode* curr = pre.top();
        pre.pop();
        int res = curr->val;
        curr = curr->left;
        while (curr) {
            pre.push(curr);
            curr = curr->right;
        }
        
        return res;
    }
    
    int getNextSuccessor(stack<TreeNode*>& suc) {
        TreeNode* curr = suc.top();
        suc.pop();
        int res = curr->val;
        curr = curr->right;
        while (curr) {
            suc.push(curr);
            curr = curr->left;
        }
        
        return res;
    }
};
