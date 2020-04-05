/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode* lastNodeNot9 = nullptr;
        ListNode* node = head;
        while (node) {
            if (node->val != 9) {
                lastNodeNot9 = node;
            }
            node = node->next;
        }
        
        if (lastNodeNot9) {
            node = lastNodeNot9->next;
            ++lastNodeNot9->val;
        }
        else {            
            node = head;
        }
        
        while (node) {
            node->val = 0;
            node = node->next;
        }
        
        if (lastNodeNot9) {
            return head;            
        }
        else {
            ListNode* result = new ListNode(1);
            result->next = head;
            return result;
        }
    }
};
