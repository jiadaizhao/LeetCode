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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
    
private:
    pair<TreeNode*, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {nullptr, 0};
        }
        
        auto p1 = dfs(root->left), p2 = dfs(root->right);
        if (p1.second > p2.second) {
            return {p1.first, p1.second + 1};
        }
        else if (p1.second < p2.second) {
            return {p2.first, p2.second + 1};
        }
        else {
            return {root, p1.second + 1};
        }
    }
};

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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<TreeNode*, TreeNode*> parents;
        queue<TreeNode*> Q;
        vector<TreeNode*> dnodes;
        Q.push(root);
        while (!Q.empty()) {
            int qs = Q.size();
            for (int i = 0; i < qs; ++i) {                
                TreeNode* node = Q.front();
                dnodes.push_back(node);
                Q.pop();
                if (node->left) {
                    parents[node->left] = node;
                    Q.push(node->left);
                }
                if (node->right) {
                    parents[node->right] = node;
                    Q.push(node->right);
                }
            }
            if (!Q.empty()) {
                dnodes.clear();
            }
        }
        
        for (auto node : dnodes) {
            Q.push(node);
        }
        
        unordered_set<TreeNode*> visited;
        while (Q.size() > 1) {
            int qs = Q.size();
            for (int i = 0; i < qs; ++i) {                
                TreeNode* node = Q.front();
                Q.pop();
                if (parents.count(node) && !visited.count(parents[node])) {
                    visited.insert(parents[node]);
                    Q.push(parents[node]);
                }
            }
        }
        return Q.front();
    }
};
