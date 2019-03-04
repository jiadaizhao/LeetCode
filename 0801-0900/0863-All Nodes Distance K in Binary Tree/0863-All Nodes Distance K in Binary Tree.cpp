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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        dfs(root, nullptr);
        queue<TreeNode*> Q;
        unordered_set<TreeNode*> visited;
        Q.push(target);
        visited.insert(target);
        int dist = 0;
        vector<int> result;
        while (!Q.empty()) {
            int qs = Q.size();
            for (int i = 0; i < qs; ++i) {
                TreeNode* node = Q.front();
                Q.pop();
                if (dist == K) {
                    result.push_back(node->val);
                }
                else {
                    if (node->left && !visited.count(node->left)) {
                        Q.push(node->left);
                        visited.insert(node->left);
                    }
                    if (node->right && !visited.count(node->right)) {
                        Q.push(node->right);
                        visited.insert(node->right);
                    }
                    if (parents[node] && !visited.count(parents[node])) {
                        Q.push(parents[node]);
                        visited.insert(parents[node]);
                    }
                }
            }
            ++dist;
        }
        return result;
    }
    
private:
    unordered_map<TreeNode*, TreeNode*> parents;
    void dfs(TreeNode* root, TreeNode* parent) {
        if (root == nullptr) {
            return;
        }
        parents[root] = parent;
        dfs(root->left, root);
        dfs(root->right, root);
    }
};
