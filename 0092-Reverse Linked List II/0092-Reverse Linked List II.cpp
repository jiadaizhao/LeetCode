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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* p = &dummy;
        int i = 0;
        while (i < m - 1) {
            p = p->next;
            ++i;
        }
        
        ListNode* curr = p->next;
        ListNode* prev = nullptr;
        while (i < n) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            ++i;
        }
        p->next->next = curr;
        p->next = prev;
        
        return dummy.next;
    }
};
