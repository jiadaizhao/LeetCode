/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* node = root;
        while (node) {
            TreeLinkNode* p = node;
            while (p) {
                if (p->left) {
                    p->left->next = p->right;
                }
                
                if (p->right && p->next) {
                    p->right->next = p->next->left;
                }
                
                p = p->next;
            }
            
            node = node->left;
        }
    }
};
