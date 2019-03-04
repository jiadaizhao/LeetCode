/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            St.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return St.size();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node = St.top();
        int val = node->val;
        St.pop();
        node = node->right;
        
        while (node) {
            St.push(node);
            node = node->left;
        }
        
        return val;
    }
    
private:
    stack<TreeNode*> St;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
