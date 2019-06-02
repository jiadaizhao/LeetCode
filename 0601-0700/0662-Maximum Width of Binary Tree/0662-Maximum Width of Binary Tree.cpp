/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // BFS
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int maxWidth = 0;
        queue<pair<int, TreeNode*>> Q;
        Q.emplace(1, root);        
        while (!Q.empty()) {
            int qs = Q.size();
            int index = -1;
            int left = Q.front().first;
            for (int i = 0; i < qs; ++i) {
                index = Q.front().first;
                TreeNode* node = Q.front().second;
                Q.pop();

                if (node->left) {
                    // Previously it's index * 2, which may have overflow issue, minus shift
                    Q.emplace((index - left + 1) * 2, node->left);
                }

                if (node->right) {
                    Q.emplace((index - left + 1) * 2 + 1, node->right);
                }
            }

            maxWidth = max(maxWidth, index - left + 1);
        }

        return maxWidth;
    }
};

// DFS
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> lefts;
        return dfs(root, 0, 1, lefts);
    }
    
private:
    int dfs(TreeNode* root, int level, int index, vector<int>& lefts) {
        if (root == nullptr) {
            return 0;
        }
        
        if (level >= lefts.size()) {
            lefts.push_back(index);
        }
        
        int leftMax = dfs(root->left, level + 1, (index - lefts[level] + 1) * 2, lefts);
        int rightMax = dfs(root->right, level + 1, (index - lefts[level] + 1) * 2 + 1, lefts);
        return max({index - lefts[level] + 1, leftMax, rightMax});
    }
};
