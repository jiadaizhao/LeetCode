/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<int> lps(1), vals(1, head->val);
        int l = 0;
        ListNode* node = head->next;
        while (node) {
            while (l && node->val != vals[l]) {
                l = lps[l - 1];
            }
            l += node->val == vals[l];
            lps.push_back(l);
            vals.push_back(node->val);
            node = node->next;
        }
        
        return dfs(root, 0, lps, vals);
    }

private:
    bool dfs(TreeNode* root, int l, vector<int>& lps, vector<int>& vals) {
        if (root == nullptr) {
            return false;
        }
        while (l && root->val != vals[l]) {
            l = lps[l - 1];
        }
        l += root->val == vals[l];
        if (l == vals.size()) {
            return true;
        }
        return dfs(root->left, l, lps, vals) || dfs(root->right, l, lps, vals);
    }
};


class Solution2 {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<int> lps(1), vals(1, head->val);
        int l = 0;
        ListNode* node = head->next;
        while (node) {
            while (l && node->val != vals[l]) {
                l = lps[l - 1];
            }
            l += node->val == vals[l];
            lps.push_back(l);
            vals.push_back(node->val);
            node = node->next;
        }
        
        return dfs(root, 0, lps, vals);
    }

private:
    bool dfs(TreeNode* root, int l, vector<int>& lps, vector<int>& vals) {
        if (root == nullptr) {
            return false;
        }
        while (l && root->val != vals[l]) {
            l = lps[l - 1];
        }
        l += root->val == vals[l];
        if (l == vals.size()) {
            return true;
        }
        return dfs(root->left, l, lps, vals) || dfs(root->right, l, lps, vals);
    }
};
