/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        stack<Node*> St1;
        unordered_set<Node*> visited;
        St1.push(root);
        TreeNode* result = new TreeNode(root->val);
        stack<TreeNode*> St2;
        St2.push(result);
        while (!St1.empty()) {
            Node* node = St1.top();
            St1.pop();
            TreeNode* curr = St2.top();
            St2.pop();
            if (node->children.size() && !visited.count(node->children[0])) {
                curr->right = new TreeNode(node->children[0]->val);
                St1.push(node->children[0]);
                visited.insert(node->children[0]);
                St2.push(curr->right);
                curr = curr->right;
                
                for (int i = 1; i < node->children.size(); ++i) {
                    curr->left = new TreeNode(node->children[i]->val);
                    St1.push(node->children[i]);
                    visited.insert(node->children[i]);
                    St2.push(curr->left);
                    curr = curr->left;
                }
            }            
        }
        
        return result;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        stack<TreeNode*> St1;
        unordered_set<TreeNode*> visited;
        St1.push(root);
        Node* result = new Node(root->val);
        stack<Node*> St2;
        St2.push(result);
        while (!St1.empty()) {
            TreeNode* treeNode = St1.top();
            St1.pop();
            Node* curr = St2.top();
            St2.pop();
            if (treeNode->right && !visited.count(treeNode->right)) {
                Node* child = new Node(treeNode->right->val);
                curr->children.push_back(child);
                St1.push(treeNode->right);
                visited.insert(treeNode->right);
                St2.push(child);
                treeNode = treeNode->right;
                
                while (treeNode->left) {
                    child = new Node(treeNode->left->val);
                    curr->children.push_back(child);
                    St1.push(treeNode->left);
                    visited.insert(treeNode->left);
                    St2.push(child);
                    treeNode = treeNode->left;
                }
            }           
        }
        
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));
