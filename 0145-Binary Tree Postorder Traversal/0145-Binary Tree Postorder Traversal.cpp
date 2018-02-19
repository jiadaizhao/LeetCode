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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        TreeNode* prev = nullptr;
        stack<TreeNode*> St;
        St.push(root);
        while (!St.empty()) {
            TreeNode* curr = St.top();
             // traverse down the tree
            if (prev == nullptr || prev->left == curr || prev->right == curr) {
                if (curr->left) {
                    St.push(curr->left);
                }
                else if (curr->right) {
                    St.push(curr->right);
                }
            }
            // traverse up the tree from the left
            else if (curr->left == prev) {
                if (curr->right) {
                    St.push(curr->right);
                }
            }
            // traverse up the tree from the right
            else {
                result.push_back(curr->val);
                St.pop();
            }
            prev = curr;
        }
        
        return result;
    }
};


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;
        while (curr) {
            if (curr->right == nullptr) {
                result.push_back(curr->val);
                curr = curr->left;
            }
            else {
                TreeNode* next = curr->right;
                while (next->left && next->left != curr) {
                    next = next->left;
                }
                
                if (next->left == nullptr) {
                    result.push_back(curr->val);
                    next->left = curr;
                    curr = curr->right;
                }
                else {
                    next->left = nullptr;
                    curr = curr->left;
                }
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
