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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        stack<TreeNode*> St1, St2;
        TreeNode *node1 = root1, *node2 = root2;
        while (node1) {
            St1.push(node1);
            node1 = node1->left;
        }
        
        while (node2) {
            St2.push(node2);
            node2 = node2->right;
        }
        
        while (!St1.empty() && !St2.empty()) {
            node1 = St1.top();
            node2 = St2.top();
            if (node1->val + node2->val < target) {
                St1.pop();
                node1 = node1->right;
                while (node1) {
                    St1.push(node1);
                    node1 = node1->left;
                }
            }
            else if (node1->val + node2->val > target) {
                St2.pop();
                node2 = node2->left;
                while (node2) {
                    St2.push(node2);
                    node2 = node2->right;
                }
            }
            else {
                return true;
            }
        }
        
        return false;
    }
};
