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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        stack<TreeNode*> St;
        TreeNode* node = root;
        while (!St.empty() || node) {
            if (node) {
                St.push(node);
                node = node->left;
            }
            else {
                node = St.top();
                result.push_back(node->val);
                St.pop();
                node = node->right;
            }
        }
        
        return result;
    }
};

// Morris traversal, O(1) space
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
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
                    prev->right = curr;
                    curr = curr->left;
                }
                else {
                    prev->right = nullptr;
                    result.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        
        return result;
    }
};
