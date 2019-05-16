/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        nodes.push_back(root);
        for (int i = 0; i < nodes.size(); ++i) {
            if (nodes[i]->left) {
                nodes.push_back(nodes[i]->left);
            }
            if (nodes[i]->right) {
                nodes.push_back(nodes[i]->right);
            }
        }
    }
    
    int insert(int v) {
        TreeNode* node = new TreeNode(v);
        nodes.push_back(node);
        TreeNode* parent = nodes[nodes.size() / 2 - 1];
        if (nodes.size() & 1) {
            parent->right = node;
        }
        else {
            parent->left = node;
        }
        return parent->val;
    }
    
    TreeNode* get_root() {
        return nodes[0];
    }
    
private:
    vector<TreeNode*> nodes;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
