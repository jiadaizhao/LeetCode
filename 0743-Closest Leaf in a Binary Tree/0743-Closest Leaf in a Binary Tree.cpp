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
    int findClosestLeaf(TreeNode* root, int k) {
        dfs(root, nullptr);
        if (graph[k].size() == 0) {
            return k;
        }
        unordered_set<int> visited;
        visited.insert(k);
        queue<int> Q;
        Q.push(k);      
        
        while (!Q.empty()) {
            int i = Q.front();
            Q.pop();
            if (graph[i].size() == 1 && i != root->val) {
                return i;
            }
            for (int j : graph[i]) {
                if (visited.find(j) == visited.end()) {
                    Q.push(j);
                    visited.insert(j);
                }
            }
        }
        
        return -1;
    }
    
private:
    unordered_map<int, unordered_set<int>> graph;
    void dfs(TreeNode* node, TreeNode* parent) {
        if (node) {
            if (parent) {
                graph[node->val].insert(parent->val);
                graph[parent->val].insert(node->val);
            }
            dfs(node->left, node);
            dfs(node->right, node);
        }
    }
};
