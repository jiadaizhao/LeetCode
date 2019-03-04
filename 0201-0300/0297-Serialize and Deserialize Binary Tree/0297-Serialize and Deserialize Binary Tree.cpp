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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "[]";
        }
        
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        for (int i = 0; i < nodes.size(); ++i) {
            TreeNode* node = nodes[i];
            if (node == nullptr) {
                continue;
            }

            nodes.push_back(node->left);
            nodes.push_back(node->right);
        }
        
        while (nodes.back() == nullptr) {
            nodes.pop_back();
        }
        
        string str = "[";
        str += to_string(nodes[0]->val);
        for (int i = 1; i < nodes.size(); ++i) {
            if (nodes[i] != nullptr) {
                str += "," + to_string(nodes[i]->val);
            }
            else {
                str += ",null";
            }
        }
        
        str += "]";
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]") {
            return nullptr;
        }
        
        vector<string> str = split(data.substr(1, data.size() - 2), ",");
        TreeNode* root = new TreeNode(stoi(str[0]));
        queue<TreeNode*> Q;
        Q.push(root);
        bool leftChild = true;
        for (int i = 1; i < str.size(); ++i) {
            if (str[i] != "null") {
                TreeNode* node = new TreeNode(stoi(str[i]));
                if (leftChild) {
                    Q.front()->left = node;
                }
                else {
                    Q.front()->right = node;
                }
                Q.push(node);
            }
            
            if (!leftChild) {
                Q.pop();
            }
            leftChild = !leftChild;
        }
        
        return root;
    }

private:
    vector<string> split(string data, string delim) {
        vector<string> result;
        int lastIndex = 0, index;
        while ((index = data.find(delim, lastIndex)) != string::npos) {
            result.push_back(data.substr(lastIndex, index - lastIndex));
            lastIndex = index + delim.size();
        }
        
        if (lastIndex != data.size()) {
            result.push_back(data.substr(lastIndex, data.size() - lastIndex));
        }
        
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
