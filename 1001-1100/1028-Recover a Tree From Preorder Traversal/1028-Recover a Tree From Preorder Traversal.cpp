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
    TreeNode* recoverFromPreorder(string S) {
        int i = 0, prev = 0;
        while (i < S.size() && S[i] != '-') {
            ++i;
        }
        TreeNode* root = new TreeNode(stoi(S.substr(0, i)));
        unordered_map<int, TreeNode*> table;
        table[0] = root;
        while (i < S.size()) {
            int start = i;
            while (i < S.size() && S[i] == '-') {
                ++i;
            }
            int curr = i - start;
            start = i;
            while (i < S.size() && S[i] != '-') {
                ++i;
            }
            TreeNode* node = new TreeNode(stoi(S.substr(start, i - start)));
            if (curr == prev + 1) {
                table[curr - 1]->left = node;
            }
            else {
                table[curr - 1]->right = node;
            }
            table[curr] = node;
            prev = curr;
        }
        
        return root;
    }
};
