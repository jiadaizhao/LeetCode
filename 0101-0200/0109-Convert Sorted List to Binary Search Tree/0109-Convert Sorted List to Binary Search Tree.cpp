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
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        return helper(head, nullptr);
    }
    
private:
    TreeNode* helper(ListNode* head, ListNode* tail) {
        if (head == tail) {
            return nullptr;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode* root = new TreeNode(slow->val);
        root->left = helper(head, slow);
        root->right = helper(slow->next, tail);
        return root;
    }
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {        
        int len = 0;
        ListNode* node = head;
        while (node) {
            ++len;
            node = node->next;
        }
        
        return helper(head, len);
    }
    
private:
    TreeNode* helper(ListNode* &head, int len) {
        if (len == 0) {
            return nullptr;
        }
        
        TreeNode* left = helper(head, len / 2);
        TreeNode* root = new TreeNode(head->val);
        root->left = left;
        head = head->next;
        root->right = helper(head, len - len / 2 - 1);
        return root;
    }
};
