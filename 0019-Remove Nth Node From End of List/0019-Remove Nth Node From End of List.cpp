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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy = ListNode(-1);
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        for (int i = 0; i < n; ++i)
        {
            fast = fast->next;
        }
        
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* next = slow->next;
        slow->next = next->next;
        delete(next);
        return dummy.next;
    }
};
