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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(-1);
        ListNode* p = &dummy;
        while (head && head->next) {
            ListNode* next = head->next->next;
            p->next = head->next;
            head->next->next = head;
            head->next = next;
            
            head = next;
            p = p->next->next;
        }
        
        p->next = head;
        return dummy.next;
    }
};
