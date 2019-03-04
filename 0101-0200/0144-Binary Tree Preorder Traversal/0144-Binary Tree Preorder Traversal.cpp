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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        stack<TreeNode*> St;
        St.push(root);
        while (!St.empty()) {
            TreeNode* node = St.top();
            result.push_back(node->val);
            St.pop();
            
            if (node->right) {
                St.push(node->right);
            }
            
            if (node->left) {
                St.push(node->left);
            }
        }
        
        return result;
    }
};

// Morris traversal, O(1) space
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;
        while (curr) {
            if (curr->left == nullptr) {
                result.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }
                
                if (prev->right == nullptr) {
                    result.push_back(curr->val);
                    prev->right = curr;
                    curr = curr->left;
                }
                else {
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        
        return result;
    }
};
