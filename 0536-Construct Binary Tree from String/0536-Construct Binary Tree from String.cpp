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
        if (s.size() == 0)
        {
            return nullptr;
        }
        return helper(s, 0, s.size() - 1);
    }
    
private:
    TreeNode* helper(string& s, int start, int end)
    {
        if (start > end)
        {
            return nullptr;
        }
        
        int sign = 1;
        int num = 0;
        int i = start;
        if (s[i] == '-')
        {
            ++i;
            sign = -1;
        }
        
        while (i <= end && isdigit(s[i]))
        {
            num = num * 10 + (s[i++] - '0');
        }
        
        num *= sign;
        TreeNode* root = new TreeNode(num);
        if (i <= end)
        {
            int balance = 1;
            start = i + 1;
            int j = i + 1;
            while (balance)
            {
                if (s[j] == '(')
                {
                    ++balance;
                }
                else if (s[j] == ')')
                {
                    --balance;
                }
                ++j;
            }
            
            TreeNode* left = helper(s, start, j - 2);
            TreeNode* right = helper(s, j + 1, end - 1);
            root->left = left;
            root->right = right;
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
            if (c == ')') {
                St.pop();
            }
            else if (isdigit(c) || c == '-') {
                int sign = 1;
                int num = 0;
                if (c == '-') {
                    ++i;
                    sign = -1;
                }
                int j = i;
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
                --i;
            }
            ++i;
        }
        
        return St.top();
    }
};
