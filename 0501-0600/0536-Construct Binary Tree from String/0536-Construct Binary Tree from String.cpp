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
    TreeNode* str2tree(string s) {
        if (s.size() == 0) {
            return nullptr;
        }
        int i = 0;
        return helper(s, i);
    }
    
private:
    TreeNode* helper(string& s, int& i) {
        int num = 0;
        int sign = 1;
        if (s[i] == '-') {
            ++i;
            sign = -1;
        }
        while (i < s.size() && isdigit(s[i])) {
            num = num * 10 + (s[i++] - '0');
        }
        
        TreeNode* root = new TreeNode(num * sign);
        if (i < s.size() && s[i] == '(') {
            ++i; // '('
            root->left = helper(s, i);
            ++i; // ')'
            
            if (i < s.size() && s[i] == '(') {
                ++i; // '('
                root->right = helper(s, i);
                ++i; // ')'
            }
        }
        
        return root;
    }
};

// Stack
class Solution {
public:
    TreeNode* str2tree(string s) {
        int n = s.size();
        if (n == 0) {
            return nullptr;
        }
        
        stack<TreeNode*> St;
        int i = 0;
        while (i < n) {
            char c = s[i];
            if (isdigit(c) || c == '-') {
                int sign = 1;
                int num = 0;
                if (c == '-') {
                    ++i;
                    sign = -1;
                }
                while (i < n && isdigit(s[i])) {                    
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                TreeNode* node = new TreeNode(sign * num);
                if (!St.empty()) {
                    TreeNode* parent = St.top();
                    if (parent->left) {
                        parent->right = node;
                    }
                    else {
                        parent->left = node;
                    }
                }
                St.push(node);
            }
            else {
                if (c == ')') {
                    St.pop();
                }
                ++i;
            }
        }
        
        return St.top();
    }
};
