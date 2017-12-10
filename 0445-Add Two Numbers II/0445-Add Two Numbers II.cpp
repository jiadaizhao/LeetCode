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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> St1;
        while (l1) {
            St1.push(l1);
            l1 = l1->next;
        }
        stack<ListNode*> St2;
        while (l2) {
            St2.push(l2);
            l2 = l2->next;
        }
        
        ListNode* head = nullptr;
        int carry = 0;
        while (St1.size() || St2.size()) {
            int sum = carry;
            if (St1.size()) {
                sum += St1.top()->val;
                St1.pop();
            }
            
            if (St2.size()) {
                sum += St2.top()->val;
                St2.pop();
            }
            
            carry = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            node->next = head;
            head = node;
        }
        
        if (carry) {
            ListNode* node = new ListNode(1);
            node->next = head;
            head = node;
        }
        
        return  head;
    }
};
