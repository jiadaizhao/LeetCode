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
struct Node {
    int index;
    TreeNode* treeNode;
    Node(int i, TreeNode* node) : index(i), treeNode(node) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int maxWidth = 0;
        queue<Node> Q;

        Q.emplace(1, root);
        
        while (!Q.empty()) {
            int qs = Q.size();
            int left = -1, right = -1;
            for (int i = 0; i < qs; ++i) {
                Node* node = &(Q.front());
                Q.pop();
                if (left == -1) {
                    left = node->index;
                }

                right = node->index;
                if (node->treeNode->left) {
                    Q.emplace(node->index * 2, node->treeNode->left);
                }

                if (node->treeNode->right) {
                    Q.emplace(node->index * 2 + 1, node->treeNode->right);
                }
            }

            maxWidth = max(maxWidth, right - left + 1);
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
        
        int leftMax = dfs(root->left, level + 1, index * 2, lefts);
        int rightMax = dfs(root->right, level + 1, index * 2 + 1, lefts);
        return max({index - lefts[level] + 1, leftMax, rightMax});
    }
};