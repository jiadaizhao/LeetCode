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
    vector<TreeNode*> allPossibleFBT(int N) {
        if (N == 0) {
            return {};
        }
        if (N == 1) {
            return {new TreeNode(0)};
        }
        if (!cache.count(N)) {
            vector<TreeNode*> result;
            for (int i = 1; i < N; i += 2) {
                vector<TreeNode*> lefts = allPossibleFBT(i);
                vector<TreeNode*> rights = allPossibleFBT(N - i - 1);
                for (TreeNode* left : lefts) {
                    for (TreeNode* right : rights) {
                        TreeNode* root = new TreeNode(0);
                        root->left = left;
                        root->right = right;
                        result.push_back(root);
                    }
                }
            }
            cache[N] = result;
        }
        return cache[N];
    }
private:
    unordered_map<int, vector<TreeNode*>> cache;
};
