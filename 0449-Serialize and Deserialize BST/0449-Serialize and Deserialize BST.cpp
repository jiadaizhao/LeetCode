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
        if (root == nullptr)
        {
            return "";
        }
        
        vector<TreeNode*> Q;
        Q.push_back(root);
        for (int i = 0; i < Q.size(); ++i)
        {
            TreeNode* node = Q[i];
            if (node == nullptr)
            {
                continue;
            }
            Q.push_back(node->left);
            Q.push_back(node->right);
        }
        
        while (Q.back() == nullptr)
        {
            Q.pop_back();
        }
        
        string result;
        for (TreeNode* node : Q)
        {
            if (node == nullptr)
            {
                result += ",null";
            }
            else if (result.size())
            {
                result += "," + to_string(node->val);
            }
            else
            {
                result += to_string(node->val);
            }
        }
        
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0)
        {
            return nullptr;
        }
        stringstream ss(data);
        queue<TreeNode*> Q;
        string s;
        TreeNode* root = nullptr;
        bool left = true;
        while (getline(ss, s, ','))
        {
            if (root == nullptr)
            {
                root = new TreeNode(stoi(s));
                Q.push(root);
            }
            else
            {
                if (s != "null")
                {
                    TreeNode* node = new TreeNode(stoi(s));
                    if (left)
                    {
                        Q.front()->left = node;
                    }
                    else
                    {
                        Q.front()->right = node;
                    }
                    Q.push(node);
                }
                
                if (!left)
                {
                    Q.pop();
                }
                
                left = !left;
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
